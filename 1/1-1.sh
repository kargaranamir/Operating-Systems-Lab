#!/bin/bash
mkdir $1 
for (( i=$3; i<=$4; i++))
do
 touch "./$1/$i.$2"
done

for i in $(ls "./$1"); do 
	echo "$1/$i"
done
