# Q5. Write a shell script that defines two functions: one for addition and one for subtraction. Call both functions with two user-given numbers.

#!/bin/bash
add() {
    echo "$(($1 + $2))"
}
subtract() {
    echo "$(($1 - $2))"
}

echo -n "Enter two numbers: "
read a b
sum=$(add $a $b)
diff=$(subtract $a $b)
echo "Sum of $a and $b is $sum"
echo "Difference of $a and $b is $diff"
