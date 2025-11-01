# Q3. Write a shell script to exchange two variables and show their value on the screen.

#!/bin/bash
echo -n "Enter two values: "
read a b
temp=$a
a=$b
b=$temp
echo "Values after swapping: a=$a and b=$b"
