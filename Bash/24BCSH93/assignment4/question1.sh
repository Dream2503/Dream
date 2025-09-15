# Q1. Write a shell script to display the digits which are in odd position in a given five-digit number.

#!/bin/bash
echo -n "Enter a 5 digit number: "
read num
echo "The digits at odd positions are: ${num:0:1}, ${num:2:1} and ${num:4:1}"
