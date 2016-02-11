#!/bin/bash

######################################################
# This part can be changed for various running options
######################################################
BOOL_DATA=T
BOOL_MC=T
#CUT=ID
#CUT=IsoSip
CUT=IdIsoSip
PERIOD=2012ABCD
BOOL_CLEAN=F
SINGLE_OR_FACT=singlePass
######################################################

# Clean old eff. files
if [ $BOOL_CLEAN = T ]; then

	echo "[INFO] Cleaning old efficiency \*.txt files..."
	cd inputData/Moriond_2012/$CUT/$PERIOD

	if [ $BOOL_MC = T ]; then
		rm eff_MC_*.txt
	fi
	if [ $BOOL_DATA = T ]; then
		rm eff_DATA_*.txt
	fi
	cd -
	echo "[INFO] Creating new efficiency \*txt files..."
fi
# end cleaning

VTXN_ARRAY=( 15 510 1015 1520 2030 3040 )
ETA_ARRAY=( 0_08 08_144 156_2 2_25 )


######
# MC #
######

if [ $BOOL_MC = T ]; then

for i in ${ETA_ARRAY[*]}; do
for j in ${VTXN_ARRAY[*]}; do

	filename="../RecoIdIsoSip/Fits/MC/vtxN/parameters/$CUT/$PERIOD/MC_${CUT}_vtxN${j}_eta$i.txt"
#	grep Eff $filename | awk '{ print $3 , $5 ; }' >> inputData/Moriond_2013/$CUT/$PERIOD/vtxN/eff_MC_$i.txt

	Eff=`grep Eff $filename | awk '{ print $3 }'`
	Eff_err=`grep Eff $filename | awk '{ print  $5}'`
	nsig=`grep nsig $filename | awk '{ print $3}'`
	sig_tail_fp_fract=`grep sig_tail_fp_fract $filename | awk '{ print $3}'`
	sig_tail_pp_fract=`grep sig_tail_pp_fract $filename | awk '{ print $3}'`

	echo $Eff $Eff_err $nsig $sig_tail_pp_fract $sig_tail_fp_fract

done
done

fi


########
# DATA #
########

if [ $BOOL_DATA = T ]; then

for i in ${ETA_ARRAY[*]}; do
for j in ${VTXN_ARRAY[*]}; do

	filename="../RecoIdIsoSip/Fits/DATA/vtxN/parameters/$CUT/$PERIOD/DATA_${CUT}_vtxN${j}_eta$i.txt"
#	grep Eff $filename | awk '{ print $3 , $5 ; }' >> inputData/Moriond_2013/$CUT/$PERIOD/vtxN/eff_DATA_$i.txt

	Eff=`grep Eff $filename | awk '{ print $3 }'`
	Eff_err=`grep Eff $filename | awk '{ print  $5}'`
	nsig=`grep nsig $filename | awk '{ print $3}'`
	sig_tail_fp_fract=`grep sig_tail_fp_fract $filename | awk '{ print $3}'`
	sig_tail_pp_fract=`grep sig_tail_pp_fract $filename | awk '{ print $3}'`

	echo $Eff $Eff_err $nsig $sig_tail_pp_fract $sig_tail_fp_fract

done
done

fi