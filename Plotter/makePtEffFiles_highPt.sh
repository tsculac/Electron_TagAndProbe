#!/bin/bash

######################################################
# This part can be changed for warious running options
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
#if [ $BOOL_CLEAN = T ]; then
#
#	echo Cleaning old eff. \*.txt files...
#	cd inputData/Moriond_2012/$CUT/$PERIOD
#
#	if [ $BOOL_MC = T ]; then
#		rm eff_MC_*.txt
#	fi
#	if [ $BOOL_DATA = T ]; then
#		rm eff_DATA_*.txt
#	fi
#	cd -
#	echo Creating new eff. \*txt files...
#fi
# end cleaning

PT_ARRAY=( 1520 2030 3040 4050 50 )
ETA_ARRAY=( eta0_08 eta08_144 eta156_2 eta2_25 )


######
# MC #
######

if [ $BOOL_MC = T ]; then

for i in ${ETA_ARRAY[*]}; do
for j in ${PT_ARRAY[*]}; do

	filename="../IdIsoSip/fits/MC/pT/parameters/$CUT/$PERIOD/MC_${CUT}_pT${j}_$i.txt"
#	grep Eff $filename | awk '{ print $3 , $5 ; }' >> inputData/Moriond_2012/$CUT/$PERIOD/eff_MC_${i}_singlePass.txt

	Eff=`grep Eff $filename | awk '{ print $3 }'`
	Eff_err=`grep Eff $filename | awk '{ print  $5}'`
	nsig=`grep nsig $filename | awk '{ print $3}'`
	sig_bump_fract_fp=`grep sig_bump_fract_fp $filename | awk '{ print $3}'`
	sig_bump_fract_pp=`grep sig_bump_fract_pp $filename | awk '{ print $3}'`
	sig_fp_convexp_fract=`grep sig_fp_convexp_fract $filename | awk '{ print $3}'`
	sig_pp_convexp_fract=`grep sig_pp_convexp_fract $filename | awk '{ print $3}'`

	echo $Eff $Eff_err $nsig $sig_bump_fract_pp$sig_pp_convexp_fract $sig_bump_fract_fp$sig_fp_convexp_fract

done
done

fi


########
# DATA #
########

if [ $BOOL_DATA = T ]; then

for i in ${ETA_ARRAY[*]}; do
for j in ${PT_ARRAY[*]}; do

	filename="../IdIsoSip/fits/DATA/pT/parameters/$CUT/$PERIOD/DATA_${CUT}_pT${j}_$i.txt"
#	grep Eff $filename | awk '{ print $3 , $5 ; }' >> inputData/Moriond_2012/$CUT/$PERIOD/eff_DATA_$i.txt

	Eff=`grep Eff $filename | awk '{ print $3 }'`
	Eff_err=`grep Eff $filename | awk '{ print  $5}'`
	nsig=`grep nsig $filename | awk '{ print $3}'`
	sig_bump_fract_fp=`grep sig_bump_fract_fp $filename | awk '{ print $3}'`
	sig_bump_fract_pp=`grep sig_bump_fract_pp $filename | awk '{ print $3}'`
	sig_fp_convexp_fract=`grep sig_fp_convexp_fract $filename | awk '{ print $3}'`
	sig_pp_convexp_fract=`grep sig_pp_convexp_fract $filename | awk '{ print $3}'`

	echo $Eff $Eff_err $nsig $sig_bump_fract_pp$sig_pp_convexp_fract $sig_bump_fract_fp$sig_fp_convexp_fract

done
done

fi
