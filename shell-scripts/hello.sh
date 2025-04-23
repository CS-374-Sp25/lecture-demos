#!/bin/bash

x="17"

x=$((x + 3))

if [[ "$x" -lt 15  ]]
then
	echo "X is less than 15!"
elif [[ "$x" -gt 19 ]]
then
	echo "X is greater than 19!"
else
	echo "X is between 15 and 19, inclusive"
fi

for f in ./*.c
do
	cat_output=$(cat $f | grep "main()")
	if [[ "$cat_output" != "" ]]
	then
		echo $f
	fi
done


