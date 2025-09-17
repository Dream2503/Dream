# Q1. Write a shell script to find the sum and average of elements in an array.

#!/bin/bash
echo -n "Enter the array elements: "
read -a array
sum=0

for element in "${array[@]}"
do
	sum=$(($sum + $element))
done

echo "The sum of all the elements of the array is $sum"
avg=$(echo "scale = 6; $sum / ${#array[@]}" | bc)
echo "The average of the elements of the array is $avg"
