# Q1. Write a shell script to ask your name, branch and SIC no and print it on the screen.

#!/bin/bash
echo -n "Enter your name, branch and SIC: "
read name branch sic
echo "You are $name of branch $branch with SIC:$sic"
