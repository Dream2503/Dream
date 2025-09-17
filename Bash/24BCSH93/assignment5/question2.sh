# Q2. Write a shell script function to find the maximum number from an array.

#!/bin/bash
find_max() {
    max=$1

    for element in "$@"
    do
        if [ $max -lt $element ]
		then
            max=$element
        fi
    done
    echo "$max"
}

echo -n "Enter the elements of the array: "
read -a array
max=$(find_max ${array[@]})
echo "The maximum element in the array is $max"
