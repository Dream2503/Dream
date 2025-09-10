# Q10. Write a shell script to generate the Fibonacci series.

#!/bin/bash
echo -n "Enter a number: "
read n
n1=0
n2=1
echo -n "The fibinacci series till $n th term is "

if [ $n -gt 0 ]
then
	echo -n "$n1 "
fi
if [ $n -gt 1 ]
then
	echo -n "$n2 "
fi
for ((i = 2; i < n; i++))
do
	temp=$n2
	n2=$((n1 + n2))
	n1=$temp
	echo -n "$n2 "
done
echo ""
