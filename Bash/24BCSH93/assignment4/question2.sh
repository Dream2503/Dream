# Q2. Write a shell script to reverse the digits of a number.

#!/bin/bash
echo -n "Enter a number: "
read num
res=0

while [ $num -ne 0 ]
do
	res=$((res * 10 + num % 10))
	num=$((num / 10))
done
echo "The reversed number is $res"
