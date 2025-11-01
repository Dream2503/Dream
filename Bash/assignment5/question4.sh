# Q4. Write a shell script to create a function that calculates the factorial of a number given as an argument.

#!/bin/bash
fact() {
    res=1

    for ((i = 2; i <= $1; i++)); do
        ((res *= i))
    done
    echo "$res"
}

echo -n "Enter a number: "
read num
res=$(fact $num)
echo "The factorial of $num is $res"
