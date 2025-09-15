# Q11. Write a shell script to generate the Fibonacci series.

#!/bin/bash
echo -n "Enter a number: "
read n
n1=0
n2=1
echo -n "The fibonacci series till $n th term is "

for ((i = 0; i < n; i++))
do
	echo -n "$n1 "
	temp=$n2
	n2=$(($n1 + $n2))
	n1=$temp
done
echo
