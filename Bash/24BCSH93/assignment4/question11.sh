# Q11. Write a shell script to find the number of occurrences of a particular digit in a given number.

#!/bin/bash
echo -n "Enter a number: "
read num
echo -n "Enter the digit you want to search: "
read d
temp=$num
cnt=0

while [ $temp -ne 0 ]
do
	if [ $(($temp % 10)) -eq $d ]
	then
		cnt=$(($cnt + 1))
	fi
	temp=$(($temp / 10))
done
echo "The digit $d is found $cnt times in $num"
