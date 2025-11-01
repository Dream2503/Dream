# Q6. Write a shell script to check whether a given string is a palindrome or not.

#!/bin/bash
echo -n "Enter a string: "
read str
i=0
j=$((${#str} - 1))

while ((i < j)); do
    if [ ${str:$i:1} != ${str:$j:1} ]; then
        echo "$str is not a palindrome"
        break
    fi
    ((i++))
    ((j--))
done
if ((i > j)); then
    echo "$str is a palindrome"
fi
