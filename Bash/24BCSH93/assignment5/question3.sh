# Q3. Write a shell script function that accepts a number and checks whether it is even or odd.

#!/bin/bash
is_even() {
	if [ $(($1 % 2)) -eq 0 ]
	then
		echo "$1 is an even number"
	else
		echo "$1 is an odd number"
	fi
}

echo -n "Enter a number: "
read num
is_even $num
