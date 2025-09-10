# Q7. Write a shell script to find the sum of the following series.
#	  Sum = 1 + 1/2 + 1/3 + …… + 1/n

#!/bin/bash
echo -n "Enter the number of iteration: "
read n
sum=0

for ((i = 1; i <= n; i++))
do
	sum=$(echo "scale = 6; $sum + 1 / $i" | bc)
done
echo "After $n iterations, the result is $sum"
