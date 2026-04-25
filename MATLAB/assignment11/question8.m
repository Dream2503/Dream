%Q8. Find the factorial of a number using recursion.

function f = fact(n)
    if n == 0 || n == 1
        f = 1;
    else
        f = n * fact(n-1);
    end
end

n = input('Enter number: ');
disp(fact(n));
