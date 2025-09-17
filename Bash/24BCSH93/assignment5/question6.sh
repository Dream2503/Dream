# Q6. Write a shell script to accept n numbers into an array, then use a function to sort the array in ascending and descending order.
#	  Display both results.

#!/bin/bash
ascending_sort() {
	for ((i = 0; i < $n - 1; i++))
	do
		for ((j = 0; j < $n - $i - 1; j++))
		do
			if [ ${array[$j]} -gt ${array[$(($j + 1))]} ]
			then
				temp=${array[$j]}
				array[$j]=${array[$(($j + 1))]}
				array[$(($j + 1))]=$temp
			fi
		done
	done
}

descending_sort() {
	for ((i = 0; i < $n - 1; i++))
	do
		for ((j = 0; j < $n - $i - 1; j++))
		do
			if [ ${array[$j]} -lt ${array[$(($j + 1))]} ]
			then
				temp=${array[$j]}
				array[$j]=${array[$(($j + 1))]}
				array[$(($j + 1))]=$temp
			fi
		done
	done
}

echo -n "Enter the array elements: "
read -a array
n=${#array[@]}

ascending_sort $array
echo "The sorted array in ascending order is ${array[@]}"
descending_sort $array
echo "The sorted array in descending order is ${array[@]}"
