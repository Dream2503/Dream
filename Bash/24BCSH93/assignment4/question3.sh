# Q3. Write a shell script to find the sum of the digits of a number.

#!/bin/bash
echo -n "Enter a number: "
read num
res=0

while [ $num -ne 0 ]
do
	res=$(($res + $num % 10))
	num=$(($num / 10))
done
echo "The sum of the digits of the number is $res"
