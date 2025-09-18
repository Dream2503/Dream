# Q3. Write a shell script function that accepts a number and checks whether it is even or odd.

#!/bin/bash
is_even() {
    if (($1 % 2 == 0)); then
        echo "even"
    else
        echo "odd"
    fi
}

echo -n "Enter a number: "
read num
res=$(is_even $num)
echo "$num is an $res number"
