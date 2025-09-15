# Q5. Write a shell script to find the GCD of two given numbers.

#!/bin/bash
echo -n "Enter two numbers: "
read n1 n2
a=$n1
b=$n2

while [ $b -ne 0 ]
do
	temp=$b
	b=$(($a % $b))
	a=$temp
done
echo "The GCD $n1 and $n2 is $a"
