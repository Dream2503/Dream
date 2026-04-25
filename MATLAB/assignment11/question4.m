%Q4. Input a number and check whether it is a prime or not.

n = input('Enter number: ');
flag = 1;

if n <= 1
    flag = 0;
else
    for i = 2:sqrt(n)
        if mod(n, i) == 0
            flag = 0;
            break;
        end
    end
end
if flag == 1
    disp('Prime number');
else
    disp('Not a prime number');
end
