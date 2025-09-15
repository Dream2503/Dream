# Q9. Write a shell script to find the factorial of a given number.

#!/bin/bash
echo -n "Enter a number: "
read num;
fact=1

for ((i = 2; i <= num; i++))
do
	fact=$(($fact * i))
done
echo "The factorial of $num is $fact"
