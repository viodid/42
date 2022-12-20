#!/bin/bash
#find . -name '*.sh'

LIST_SH="$(find . -type f -iname '*.sh')"


for file in $LIST_SH
do
	printf "%s\n" "$file" | sed "s/.*\///" | cut -d "." -f1
done
