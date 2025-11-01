# Q11. Write a shell script to find the number of occurrences of a particular digit in a given number.

#!/bin/bash
echo -n "Enter a number: "
read num
echo -n "Enter the digit you want to search: "
read d
temp=$num
cnt=0

while ((temp != 0)); do
    if ((temp % 10 == d)); then
        ((cnt++))
    fi
    ((temp /= 10))
done
echo "The digit $d is found $cnt times in $num"
