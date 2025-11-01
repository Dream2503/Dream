# Q4. Write a shell script to find the position of a substring in a given string.

#!/bin/bash
echo -n "Enter the main string: "
read str
echo -n "Enter the substring: "
read sub
i=0
sub_len=${#sub}
max_len=$((${#str} - sub_len + 1))

while ((i < max_len)); do
    j=0

    while ((j < sub_len)); do
        idx=$((i + j))

        if [ ${str:idx:1} != ${sub:j:1} ]; then
            break
        fi
        ((j++))
    done
    if ((j == sub_len)); then
        echo "Substring found at position $i"
        break
    fi
    ((i++))
done
if ((i == max_len)); then
    echo "Substring not found"
fi
