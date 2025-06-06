#!/bin/bash

	x="1"

	for y in `echo 0 1 01 1.0 2 abc -3.143`; do
		if [ $x == $y ]; then
			echo "$x == $y"
		elif [ $x -eq $y ] 2> /dev/null; then
			echo "$x -eq $y"
		elif [ `echo "$x == $y" | bc` == 1 ]; then
			echo "$x -eq $y (using bc)"
		elif [ $y == "abc" ]; then
			echo "(for $y: continue)"
			continue
		else
			echo "$x and $y are different"
		fi
	done

exit 0

