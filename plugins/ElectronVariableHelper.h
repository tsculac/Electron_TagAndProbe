#ifndef _ELECTRONVARIABLEHELPER_H
#define _ELECTRONVARIABLEHELPER_H

#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1EmParticleFwd.h"

#include <DataFormats/PatCandidates/interface/Electron.h>
#include <DataFormats/PatCandidates/interface/Photon.h>


#include "DataFormats/Math/interface/deltaR.h"
#include <map>

template <class T>
class ElectronVariableHelper : public edm::EDProducer {
 public:
  explicit ElectronVariableHelper(const edm::ParameterSet & iConfig);
  virtual ~ElectronVariableHelper() ;
  
  virtual void produce(edm::Event & iEvent, const edm::EventSetup & iSetup) override;
  
private:
  edm::EDGetTokenT<std::vector<T> > probesToken_;
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > electronsToken_; //added a new Token needed for BDTValue calculation
  edm::EDGetTokenT<pat::ElectronCollection> electronToken_; //electrons
  edm::EDGetTokenT<edm::View<pat::PackedCandidate> > photonToken_; //photons
  edm::EDGetTokenT<reco::VertexCollection> vtxToken_;
  edm::EDGetTokenT<l1extra::L1EmParticleCollection> l1NonIsoToken_;
  edm::EDGetTokenT<l1extra::L1EmParticleCollection> l1IsoToken_;
  edm::EDGetTokenT<double> rhoToken_;
  edm::EDGetTokenT<edm::ValueMap<float> > BDTValueMapToken_;
  edm::EDGetTokenT<edm::View<pat::PackedCandidate> > pfCandToken;
};

template<class T>
ElectronVariableHelper<T>::ElectronVariableHelper(const edm::ParameterSet & iConfig) :
  probesToken_(consumes<std::vector<T> >(iConfig.getParameter<edm::InputTag>("probes"))),
  electronsToken_(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("probes"))),//setting input tag for BDT calculation to probe electrons
  electronToken_(consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("probes"))),
  photonToken_(consumes<edm::View<pat::PackedCandidate> >(iConfig.getParameter<edm::InputTag>("photonSrc"))),
  vtxToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertexCollection"))),
  l1NonIsoToken_(consumes<l1extra::L1EmParticleCollection>(edm::InputTag("l1extraParticles:NonIsolated"))),
  l1IsoToken_(consumes<l1extra::L1EmParticleCollection>(edm::InputTag("l1extraParticles:Isolated"))),
  rhoToken_(consumes<double>(edm::InputTag("fixedGridRhoFastjetAll"))),
  BDTValueMapToken_(consumes<edm::ValueMap<float> >(iConfig.getParameter<edm::InputTag>("mvaValuesMap"))),
  pfCandToken(consumes<edm::View<pat::PackedCandidate> >(edm::InputTag("packedPFCandidates")))

{

  produces<edm::ValueMap<float> >("dz");
  produces<edm::ValueMap<float> >("dxy");
  produces<edm::ValueMap<float> >("missinghits");
  produces<edm::ValueMap<float> >("l1et");
  produces<edm::ValueMap<float> >("passingSpring15NonTrig"); // adding a value map to store BDT passing/failing information
  produces<edm::ValueMap<float> >("effarea");
  produces<edm::ValueMap<float> >("rho");
  produces<edm::ValueMap<float> >("enedens");
  produces<edm::ValueMap<float> >("iso");
  produces<edm::ValueMap<float> >("ip");
  produces<edm::ValueMap<float> >("iperror");
  produces<edm::ValueMap<float> >("sip");
  produces<edm::ValueMap<float> >("FSRcorr");
  produces<edm::ValueMap<float> >("FSRpx");
  produces<edm::ValueMap<float> >("FSRpy");
  produces<edm::ValueMap<float> >("FSRpz");
  produces<edm::ValueMap<float> >("FSRe");
  produces<edm::ValueMap<float> >("correctediso");
}

template<class T>
ElectronVariableHelper<T>::~ElectronVariableHelper()
{}

template<class T>
void ElectronVariableHelper<T>::produce(edm::Event & iEvent, const edm::EventSetup & iSetup) {

  // read input
  edm::Handle<std::vector<T> > probes;
  edm::Handle<reco::VertexCollection> vtxH;
  edm::Handle<std::vector<l1extra::L1EmParticle> > l1NonIsoH, l1IsoH;
  edm::Handle<edm::ValueMap<float> > BDTValues;
  edm::Handle<edm::View<reco::GsfElectron> > electrons;//collection of electrones for BDT calculation
  
  iEvent.getByToken(electronsToken_, electrons);//copying probes to electrons
  iEvent.getByToken(probesToken_,  probes);
  iEvent.getByToken(vtxToken_, vtxH);
  const reco::VertexRef vtx(vtxH, 0);
  iEvent.getByToken(l1NonIsoToken_, l1NonIsoH);
  const l1extra::L1EmParticleCollection* l1NonIso = l1NonIsoH.product();
  iEvent.getByToken(l1IsoToken_, l1IsoH);
  const l1extra::L1EmParticleCollection* l1Iso = l1IsoH.product();
  iEvent.getByToken(BDTValueMapToken_, BDTValues);

  // prepare vector for output
  std::vector<float> dzValues;
  std::vector<float> dxyValues;
  std::vector<float> mhValues;
  std::vector<float> l1Values;
  std::vector<float> passingSpring15NonTrigValues;
  std::vector<float> effValues;
  std::vector<float> rhoValues;
  std::vector<float> edValues;
  std::vector<float> isoValues;
  std::vector<float> ipValues;
  std::vector<float> iperrorValues;
  std::vector<float> sipValues;
  std::vector<float> FSRcorrValues;
  std::vector<float> FSRpxValues;
  std::vector<float> FSRpyValues;
  std::vector<float> FSRpzValues;
  std::vector<float> FSReValues;
  std::vector<float> correctedisoValues;


  typename std::vector<T>::const_iterator probe, endprobes = probes->end();

  for (probe = probes->begin(); probe != endprobes; ++probe) {
    
    dzValues.push_back(probe->gsfTrack()->dz(vtx->position()));
    dxyValues.push_back(probe->gsfTrack()->dxy(vtx->position()));
    mhValues.push_back(float(probe->gsfTrack()->hitPattern().numberOfHits(reco::HitPattern::MISSING_INNER_HITS)));
    
    float l1et = -1;
    float dRmin = 99999;
    for (l1extra::L1EmParticleCollection::const_iterator l1It = l1Iso->begin(); l1It != l1Iso->end(); l1It++) {
      float dR = deltaR(*l1It, *(probe->superCluster()));
      if (dR < dRmin) {
	dRmin = dR;
	l1et = l1It->et();
      }
    }
     
    if (l1et < 0) {
      for (l1extra::L1EmParticleCollection::const_iterator l1It = l1NonIso->begin(); l1It != l1NonIso->end(); l1It++) {
	float dR = deltaR(*l1It, *(probe->superCluster()));
	if (dR < dRmin) {
	  dRmin = dR;
	  l1et = l1It->et();
	}
      }
    }
    
    l1Values.push_back(l1et);
  }

    for (unsigned int i = 0; i< electrons->size(); ++i){ //index loop over probes (for some reason implemetation with iterator does not work
        
        float BDT = 0.;
        const auto el = electrons->ptrAt(i);
        
        BDT = (*BDTValues)[el]; //calculating the BDT value of the probe
        
        float fSCeta = fabs(el->superCluster()->eta());
        float pt = el->pt();
        
        
        bool isBDT = (pt <= 10 && ((fSCeta < 0.8                    && BDT > -0.265) ||
                                   (fSCeta >= 0.8 && fSCeta < 1.479 && BDT > -0.556) ||
                                   (fSCeta >= 1.479                 && BDT > -0.551)   )) ||
                     (pt >  10 && ((fSCeta < 0.8                    && BDT > -0.072) ||
                                   (fSCeta >= 0.8 && fSCeta < 1.479 && BDT > -0.286) ||
                                   (fSCeta >= 1.479                 && BDT > -0.267)   ));
        
        passingSpring15NonTrigValues.push_back(int(isBDT));
    }
    
    
    edm::Handle<pat::ElectronCollection> electronHandle;
    iEvent.getByLabel("slimmedElectrons", electronHandle);
    
    for(unsigned int iele=0; iele<electronHandle->size(); iele++){//begin loop over electrons
        
        const pat::Electron* e = &((*electronHandle)[iele]);
        
        float rho_ = 0.0;
        
        edm::Handle<double> rhos;
        iEvent.getByToken(rhoToken_, rhos);
        rho_ = *rhos;
        
        rhoValues.push_back(rho_);
        
        //effective area
        float eff_area = 0.0;
        if (std::abs(e->superCluster()->eta()) >= 0.0 && std::abs(e->superCluster()->eta()) < 1.0 ) { eff_area = 0.1752; }
        if (std::abs(e->superCluster()->eta()) >= 1.0 && std::abs(e->superCluster()->eta()) < 1.479 ) { eff_area = 0.1862; }
        if (std::abs(e->superCluster()->eta()) >= 1.479 && std::abs(e->superCluster()->eta()) < 2.0 ) { eff_area = 0.1411; }
        if (std::abs(e->superCluster()->eta()) >= 2.0 && std::abs(e->superCluster()->eta()) < 2.2 ) { eff_area = 0.1534; }
        if (std::abs(e->superCluster()->eta()) >= 2.2 && std::abs(e->superCluster()->eta()) < 2.3 ) { eff_area = 0.1903; }
        if (std::abs(e->superCluster()->eta()) >= 2.3 && std::abs(e->superCluster()->eta()) < 2.4 ) { eff_area = 0.2243; }
        if (std::abs(e->superCluster()->eta()) >= 2.4) { eff_area = 0.2687; }
        
        
        effValues.push_back(eff_area);
        
        float en_dens = eff_area * rho_;
        
        edValues.push_back(en_dens);
        
        //Calculate isolation with R=0.3 cone size
        float PFChargedHadIso   = e->pfIsolationVariables().sumChargedHadronPt;
        float PFNeutralHadIso   = e->pfIsolationVariables().sumNeutralHadronEt;
        float PFPhotonIso       = e->pfIsolationVariables().sumPhotonEt;
        float pt	          = e->pt();
        
        float IP      = std::abs(e->dB(pat::Electron::PV3D));
        float IPError = e->edB(pat::Electron::PV3D);
        float SIP = 0.0;
        
        if (IPError != 0.) { SIP = IP/IPError; }
        
        ipValues.push_back(IP);
        iperrorValues.push_back(IPError);
        sipValues.push_back(SIP);
        
        float inter = PFNeutralHadIso + PFPhotonIso - rho_ * eff_area;
        if (inter < 0.0) { inter = 0; }
        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  FSR recovery calculation  //////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        edm::Handle<edm::View<pat::PackedCandidate> > photons;
        iEvent.getByToken(photonToken_, photons);
        
        std::vector<const pat::PackedCandidate*> FSRcandidate;
        
        double FSRcorr = 0.;
        double FSRpx = 0.;
        double FSRpy = 0.;
        double FSRpz = 0.;
        double FSRe = 0.;
        
        for (unsigned int j=0;j<photons->size();++j) {//begin loop over photons
            
            
            //Discard electrons that do not pass loose ID and SIP, break loop over photons because they can not have FSR
            if (!(SIP < 4.0 && e->pt() > 7. &&  std::abs(e->eta()) < 2.5 && std::abs(e->gsfTrack()->dxy(vtx->position())) < 0.5 && std::abs(e->gsfTrack()->dz(vtx->position())) < 1.)) break;
            
            const pat::PackedCandidate* g = &((*photons)[j]);
            if(!(g->pdgId()==22 && g->charge()==0 and g->pt()>2.)) continue;//check if PF Candidate is a photon
            
            if (!(g->pt()>2. && std::abs(g->eta())<2.4)) continue; //preselection CUT, if photon does not pass it go to the next one
            
            edm::Handle<edm::View<pat::PackedCandidate> > pfCands;
            iEvent.getByToken(pfCandToken, pfCands);
            
            // hardcoded cut values
            const double cut_deltaR = 0.3;
            const double cut_deltaRself_ch = 0.0001;
            const double cut_deltaRself_ne = 0.01;
            
            double ptSumNe=0.;
            double ptSumCh=0.;
            double gRelIso=0.;
            
            //Calculation of photon relative PF isolation
            std::map<const reco::Vertex*, double> ptSumByPV;
            for( edm::View<pat::PackedCandidate>::const_iterator pf = pfCands->begin(); pf!=pfCands->end(); ++pf ) {//begin loop over PF candidates
                double dr = deltaR(g->p4(), pf->p4()) ;
                if (dr>=cut_deltaR) continue;
                
                int pdgId= abs(pf->pdgId());
                
                //neutral hadrons + photons
                if (pf->charge()==0) {
                    if (dr>cut_deltaRself_ne && pf->pt()>0.5 && (pdgId==22|| pdgId==130)) {
                        ptSumNe += pf->pt();
                    }
                    // charged hadrons 
                } else {
                    if (dr>cut_deltaRself_ch && pf->pt()> 0.2 && pdgId==211) {
                        ptSumCh += pf->pt();
                        ptSumByPV[pf->vertexRef().get()] += pf->pt();
                    }
                }
                           }//end loop over PF candidates
            
            gRelIso = (ptSumNe + ptSumCh)/g->pt();
            
            if(gRelIso >= 1.8) continue; //preselection cut on PF iso
            
            double dRsc = reco::deltaR(*(e->superCluster()), *g);
            if ((std::abs(g->eta() - e->superCluster()->eta())<0.05 && std::abs(reco::deltaPhi(g->phi(), e->superCluster()->phi()))<2.) || dRsc<0.15) continue;//SCVeto
            
            //Checking if this electron is the closest one
            double dRele = deltaR(e->momentum(),g->momentum());
            if (dRele>0.5) continue; // if they are not close disregard this photon as possible FSR
            bool isClosestelectron = true;
            
            for(unsigned int k=0; k<electronHandle->size(); k++){//begin loop over electrons to check if this is the closest one among those passing loose ID and SIP
                const pat::Electron* Ce = &((*electronHandle)[k]);
                
                float IPtmp      = std::abs(Ce->dB(pat::Electron::PV3D));
                float IPErrortmp = Ce->edB(pat::Electron::PV3D);
                float SIPtmp = 0.0;
                
                if (IPErrortmp != 0.) { SIPtmp = IPtmp/IPErrortmp; }
                
                if (!(SIPtmp < 4.0 && Ce->pt() > 7. &&  std::abs(Ce->eta()) < 2.5 && std::abs(Ce->gsfTrack()->dxy(vtx->position())) < 0.5 && std::abs(Ce->gsfTrack()->dz(vtx->position())) < 1.)) continue;
                
                double dRtmp = deltaR(Ce->momentum(),g->momentum());
                if (dRtmp<dRele) isClosestelectron = false;
            }//end loop over electrons
            if(!isClosestelectron) continue; //If for the photon this is not the closest electron, move to the next photon
            
            if (!(dRele/g->pt()/g->pt() < 0.012)) continue; //If photon does not satisfy this condition it is also not an FSR photon
            
            FSRcandidate.push_back(g);
            
        }//end loop over photons
        
        //Checking if there are multiple FSR candidates and choosing the closest one
        if (FSRcandidate.size() == 0) {
          FSRcorr+= 0.;
          FSRpx+= 0.;
          FSRpy+= 0.;
          FSRpz+= 0.;
          FSRe+= 0.;
        }
        else if (FSRcandidate.size() == 1){
          double dRFINAL = deltaR(e->momentum(),FSRcandidate.at(0)->momentum());
          if ((dRFINAL < 0.3 && (std::abs(e->superCluster()->eta()) < 1.479 || dRFINAL > 0.08))) FSRcorr+=FSRcandidate.at(0)->pt();//only correct isolation if FSR photon is in the isolation cone and passing isolation veto
          FSRpx+= FSRcandidate.at(0)->px();
          FSRpy+= FSRcandidate.at(0)->py();
          FSRpz+= FSRcandidate.at(0)->pz();
          FSRe+= FSRcandidate.at(0)->energy();
        }
        else if (FSRcandidate.size() > 1){
            double dRtmpSTART = 999.;
            int index_FSR = 999;
            for(unsigned int i_fsr = 0; i_fsr < FSRcandidate.size(); i_fsr++){//start loop over FSR candidates to determine the closest one
              double dRtmp2 = deltaR(e->momentum(),FSRcandidate.at(i_fsr)->momentum())/FSRcandidate.at(i_fsr)->pt()/FSRcandidate.at(i_fsr)->pt();
                if(dRtmp2 < dRtmpSTART) {dRtmpSTART = dRtmp2; index_FSR=i_fsr;}
            }//end loop over FSR candidates
            
            double dRFINAL = deltaR(e->momentum(),FSRcandidate.at(index_FSR)->momentum());
            if ((dRFINAL < 0.3 && (std::abs(e->superCluster()->eta()) < 1.479 || dRFINAL > 0.08))) FSRcorr+=FSRcandidate.at(index_FSR)->pt();//only correct isolation if FSR photon is in the isolation cone and passing isolation veto
            FSRpx+= FSRcandidate.at(index_FSR)->px();
            FSRpy+= FSRcandidate.at(index_FSR)->py();
            FSRpz+= FSRcandidate.at(index_FSR)->pz();
            FSRe+= FSRcandidate.at(index_FSR)->energy();
        }
        
        
        FSRcorrValues.push_back(FSRcorr);
        FSRpxValues.push_back(FSRpx);
        FSRpyValues.push_back(FSRpy);
        FSRpzValues.push_back(FSRpz);
        FSReValues.push_back(FSRe);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        float iso = (PFChargedHadIso + inter)/pt;
        float correctediso = (PFChargedHadIso + std::max(0.0,(inter - FSRcorr)))/pt;
        
        isoValues.push_back(iso);
        correctedisoValues.push_back(correctediso);
        
        
    }//end loop over electrons

  
  // convert into ValueMap and store
  std::auto_ptr<edm::ValueMap<float> > dzValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler dzFiller(*dzValMap);
  dzFiller.insert(probes, dzValues.begin(), dzValues.end());
  dzFiller.fill();
  iEvent.put(dzValMap, "dz");

  std::auto_ptr<edm::ValueMap<float> > dxyValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler dxyFiller(*dxyValMap);
  dxyFiller.insert(probes, dxyValues.begin(), dxyValues.end());
  dxyFiller.fill();
  iEvent.put(dxyValMap, "dxy");

  std::auto_ptr<edm::ValueMap<float> > mhValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler mhFiller(*mhValMap);
  mhFiller.insert(probes, mhValues.begin(), mhValues.end());
  mhFiller.fill();
  iEvent.put(mhValMap, "missinghits");

  std::auto_ptr<edm::ValueMap<float> > l1ValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler l1Filler(*l1ValMap);
  l1Filler.insert(probes, l1Values.begin(), l1Values.end());
  l1Filler.fill();
  iEvent.put(l1ValMap, "l1et");
    
  std::auto_ptr<edm::ValueMap<float> > effValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler effFiller(*effValMap);
  effFiller.insert(probes, effValues.begin(), effValues.end());
  effFiller.fill();
  iEvent.put(effValMap, "effarea");
    
  std::auto_ptr<edm::ValueMap<float> > rhoValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler rhoFiller(*rhoValMap);
  rhoFiller.insert(probes, rhoValues.begin(), rhoValues.end());
  rhoFiller.fill();
  iEvent.put(rhoValMap, "rho");
    
  std::auto_ptr<edm::ValueMap<float> > edValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler edFiller(*edValMap);
  edFiller.insert(probes, edValues.begin(), edValues.end());
  edFiller.fill();
  iEvent.put(edValMap, "enedens");
    
  std::auto_ptr<edm::ValueMap<float> > isoValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler isoFiller(*isoValMap);
  isoFiller.insert(probes, isoValues.begin(), isoValues.end());
  isoFiller.fill();
  iEvent.put(isoValMap, "iso");
    
  std::auto_ptr<edm::ValueMap<float> > correctedisoValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler correctedisoFiller(*correctedisoValMap);
  correctedisoFiller.insert(probes, correctedisoValues.begin(), correctedisoValues.end());
  correctedisoFiller.fill();
  iEvent.put(correctedisoValMap, "correctediso");
    
  std::auto_ptr<edm::ValueMap<float> > passingSpring15NonTrigValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler passingSpring15NonTrigFiller(*passingSpring15NonTrigValMap);
  passingSpring15NonTrigFiller.insert(electrons, passingSpring15NonTrigValues.begin(), passingSpring15NonTrigValues.end());
  passingSpring15NonTrigFiller.fill();
  iEvent.put(passingSpring15NonTrigValMap, "passingSpring15NonTrig");
    
  std::auto_ptr<edm::ValueMap<float> > ipValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler ipFiller(*ipValMap);
  ipFiller.insert(probes, ipValues.begin(), ipValues.end());
  ipFiller.fill();
  iEvent.put(ipValMap, "ip");
    
    
  std::auto_ptr<edm::ValueMap<float> > iperrorValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler iperrorFiller(*iperrorValMap);
  iperrorFiller.insert(probes, iperrorValues.begin(), iperrorValues.end());
  iperrorFiller.fill();
  iEvent.put(iperrorValMap, "iperror");
    
    
  std::auto_ptr<edm::ValueMap<float> > sipValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler sipFiller(*sipValMap);
  sipFiller.insert(probes, sipValues.begin(), sipValues.end());
  sipFiller.fill();
  iEvent.put(sipValMap, "sip");
    
  std::auto_ptr<edm::ValueMap<float> > FSRcorrValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler FSRcorrFiller(*FSRcorrValMap);
  FSRcorrFiller.insert(probes, FSRcorrValues.begin(), FSRcorrValues.end());
  FSRcorrFiller.fill();
  iEvent.put(FSRcorrValMap, "FSRcorr");
    
  std::auto_ptr<edm::ValueMap<float> > FSRpxValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler FSRpxFiller(*FSRpxValMap);
  FSRpxFiller.insert(probes, FSRpxValues.begin(), FSRpxValues.end());
  FSRpxFiller.fill();
  iEvent.put(FSRpxValMap, "FSRpx");
    
  std::auto_ptr<edm::ValueMap<float> > FSRpyValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler FSRpyFiller(*FSRpyValMap);
  FSRpyFiller.insert(probes, FSRpyValues.begin(), FSRpyValues.end());
  FSRpyFiller.fill();
  iEvent.put(FSRpyValMap, "FSRpy");
    
  std::auto_ptr<edm::ValueMap<float> > FSRpzValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler FSRpzFiller(*FSRpzValMap);
  FSRpzFiller.insert(probes, FSRpzValues.begin(), FSRpzValues.end());
  FSRpzFiller.fill();
  iEvent.put(FSRpzValMap, "FSRpz");
    
  std::auto_ptr<edm::ValueMap<float> > FSReValMap(new edm::ValueMap<float>());
  edm::ValueMap<float>::Filler FSReFiller(*FSReValMap);
  FSReFiller.insert(probes, FSReValues.begin(), FSReValues.end());
  FSReFiller.fill();
  iEvent.put(FSReValMap, "FSRe");


}

#endif
