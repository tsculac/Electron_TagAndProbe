#!/bin/bash

######################################################
# This part can be changed for warious running options
######################################################
BOOL_DATA=T
BOOL_MC=T
#CUT=ID
#CUT=IsoSip
#CUT=IdIsoSip
PERIOD=2012ABCD
######################################################

CUT_ARRAY=( ID IsoSip )
PT_ARRAY=( 710 1015 )
ETA_ARRAY=( EB EE )


for k in ${CUT_ARRAY[*]}; do

echo ${k}

######
# MC #
######

if [ $BOOL_MC = T ]; then

for i in ${ETA_ARRAY[*]}; do
for j in ${PT_ARRAY[*]}; do

	filename="../IdIsoSip/fits/MC/pT/parameters/${k}/$PERIOD/MC_${k}_pT${j}_${i}.txt"
#	grep Eff $filename | awk '{ print $3 , $5 ; }'

	Eff=`grep Eff $filename | awk '{ print $3 }'`
	Eff_err=`grep Eff $filename | awk '{ print  $5}'`
	nsig=`grep nsig $filename | awk '{ print $3}'`
	sig_bump_fract_fp=`grep sig_bump_fract_fp $filename | awk '{ print $3}'`
	sig_bump_fract_pp=`grep sig_bump_fract_pp $filename | awk '{ print $3}'`
	sig_tail_fp_fract=`grep sig_tail_fp_fract $filename | awk '{ print $3}'`
	sig_tail_pp_fract=`grep sig_tail_pp_fract $filename | awk '{ print $3}'`

	echo $Eff $Eff_err $nsig $sig_bump_fract_pp$sig_tail_pp_fract $sig_bump_fract_fp$sig_tail_fp_fract

done
done

fi


########
# DATA #
########


if [ $BOOL_DATA = T ]; then

for i in ${ETA_ARRAY[*]}; do
for j in ${PT_ARRAY[*]}; do

	filename="../IdIsoSip/fits/DATA/pT/parameters/${k}/$PERIOD/DATA_${k}_pT${j}_$i.txt"
#	grep Eff $filename | awk '{ print $3 , $5 ; }'

	Eff=`grep Eff $filename | awk '{ print $3 }'`
	Eff_err=`grep Eff $filename | awk '{ print  $5}'`
	nsig=`grep nsig $filename | awk '{ print $3}'`
	sig_bump_fract_fp=`grep sig_bump_fract_fp $filename | awk '{ print $3}'`
	sig_bump_fract_pp=`grep sig_bump_fract_pp $filename | awk '{ print $3}'`
	sig_tail_fp_fract=`grep sig_tail_fp_fract $filename | awk '{ print $3}'`
	sig_tail_pp_fract=`grep sig_tail_pp_fract $filename | awk '{ print $3}'`

	echo $Eff $Eff_err $nsig $sig_bump_fract_pp$sig_tail_pp_fract $sig_bump_fract_fp$sig_tail_fp_fract

done
done

fi

done
