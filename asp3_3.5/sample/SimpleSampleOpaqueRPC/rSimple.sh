#!/bin/sh

N=0
while [ $N -lt $1 ]
do
	rSimple/SimpleSample-rSimple.exe
	N=$((N+1))
	echo "pass $N"
done
