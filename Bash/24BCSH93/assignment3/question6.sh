# Q6. Write a shell script to find the largest and smallest among three numbers accepted from the user.

#!/bin/bash
echo -n "Enter three numbers: "
read a b c
max=$a
min=$a

if [ $max -lt $b ]
then
	max=$b
fi
if [ $min -gt $b ]
then
	min=$b
fi
if [ $max -lt $c ]
then
	max=$c
fi
if [ $min -gt $c ]
then
	min=$c
fi

echo "The largest number is $max"
echo "The smallest number is $min"
