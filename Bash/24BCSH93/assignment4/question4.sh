# Q4. Write a shell script to find the position of a substring in a given string.

#!/bin/bash
echo -n "Enter the main string: "
read str
echo -n "Enter the substring: "
read sub
i=0
str_len=${#str}
sub_len=${#sub}
max_len=$(($str_len - $sub_len + 1))

while [ $i -lt $max_len ]
do
	j=0

	while [ $j -lt $sub_len ]
	do
		idx=$((i + j))

		if [ ${str:$idx:1} != ${sub:$j:1} ]
		then
			break
		fi
		j=$((j + 1))
	done
	if [ $j -eq $sub_len ]
	then
		echo "Substring found at position $i"
		break
	fi
	i=$((i + 1))
done
if [ $i -eq $max_len ]
then
	echo "Substring not found"
fi
