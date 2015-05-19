#!/bin/bash
declare -A value

while read line
do
	for word in $line
	do
		let value[$word]++
	done
done <input.txt

(for key in ${!value[@]}
do
	printf "%s %d\n" $key ${value[$key]}
done) | sort -r -n -t ' ' -k 2
