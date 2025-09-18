# Q7. Write a shell script to accept an array of integers, then create two functions:
#     1. One function to return the sum of even numbers.
#     2. Another function to return the sum of odd numbers.

#!/bin/bash
even_sum() {
    sum=0

    for element in "${array[@]}"; do
        if ((element % 2 == 0)); then
            ((sum += element))
        fi
    done
    echo "$sum"
}
odd_sum() {
    sum=0

    for element in "${array[@]}"; do
        if ((element % 2 == 1)); then
            ((sum += element))
        fi
    done
    echo "$sum"
}

echo -n "Enter the array elements: "
read -a array
even=$(even_sum ${array[@]})
odd=$(odd_sum ${array[@]})
echo "The sum of even elements are $even"
echo "The sum of odd elements are $odd"
