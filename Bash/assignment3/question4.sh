# Q4. Write a shell script to find whether a given number is even or odd.

#!/bin/bash
echo -n "Enter a number: "
read n

if ((n % 2 == 0)); then
    echo "$n is an even number"
else
    echo "$n is an odd number"
fi
