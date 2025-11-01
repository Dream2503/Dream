# Q6. Write a shell script to accept n numbers into an array, then use a function to sort the array in ascending and descending order.
#	  Display both results.

#!/bin/bash
ascending_sort() {
    arr=("$@")
    n=$#

    for ((i = 0; i < n - 1; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if ((arr[j] > arr[j + 1])); then
                temp=${arr[j]}
                arr[j]=${arr[j + 1]}
                arr[j + 1]=$temp
            fi
        done
    done
    echo "${arr[@]}"
}
descending_sort() {
    arr=("$@")
    n=$#

    for ((i = 0; i < n - 1; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            if ((arr[j] < arr[j + 1])); then
                temp=${arr[j]}
                arr[j]=${arr[j + 1]}
                arr[j + 1]=$temp
            fi
        done
    done
    echo "${arr[@]}"
}

echo -n "Enter the array elements: "
read -a array

asc_sorted=$(ascending_sort ${array[@]})
echo "The sorted array in ascending order is ${asc_sorted[@]}"
des_sorted=$(descending_sort ${array[@]})
echo "The sorted array in descending order is ${des_sorted[@]}"
