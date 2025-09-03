# Q2. Write a shell script to find the sum and average of the four integers entered from the keyboard.

#!/bin/bash
echo -n "Enter four numbers: "
read a b c d
sum=$((a + b + c + d))
average=$((sum / 4))
echo "The sum is $sum and the average is $average"
