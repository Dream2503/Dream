%Q7. Evaluate the following expression.
%    Cos(x) = 1-x2/2!+x4/4!+………..+ xn/n!

x = input('Enter value (in radians): ');
n = input('Enter number of terms: ');

cosx = 1;
sign = -1;

for i = 2:2:n
    term = (x^i) / factorial(i);
    cosx = cosx + sign * term;
    sign = -sign;
end
disp(['Cos(x) = ', num2str(cosx)]);
