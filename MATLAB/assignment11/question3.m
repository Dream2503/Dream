%Q3. Find the greatest number among three unequal numbers.

a = input('Enter first number: ');
b = input('Enter second number: ');
c = input('Enter third number: ');

if a > b && a > c
    disp(['Greatest is: ', num2str(a)])
elseif b > c
    disp(['Greatest is: ', num2str(b)])
else
    disp(['Greatest is: ', num2str(c)])
end
