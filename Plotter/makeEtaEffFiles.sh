#!/bin/bash

######################################################
# This part can be changed for warious running options
######################################################
BOOL_DATA=T
BOOL_MC=T
######################################################

EFF_DATA=( eff_DATA_EB.txt eff_DATA_EE.txt )
EFF_MC=( eff_MC_EB.txt eff_MC_EE.txt )
PT_ARRAY=( 710 1015 1520 2030 3040 4050 5060 60 )
PT_ARRAY_SIZE=7


########
# DATA #
########

i=0

if [ $BOOL_DATA = T ]; then

while (( i < $PT_ARRAY_SIZE ))
do
	DONE=false
	j=0
	until $DONE; do
	read LINE || DONE=true
	echo $LINE >> eff_DATA_${PT_ARRAY[j]}.txt
	j=$((j+1))
	done < ${EFF_DATA[i]}

i=$((i+1))

done
fi

######
# MC #
######

i=0

if [ $BOOL_MC = T ]; then

while (( i < $PT_ARRAY_SIZE ))
do
	DONE=false
	j=0
	until $DONE; do
	read LINE || DONE=true
	echo $LINE >> eff_MC_${PT_ARRAY[j]}.txt
	j=$((j+1))
	done < ${EFF_MC[i]}

i=$((i+1))

done
fi
