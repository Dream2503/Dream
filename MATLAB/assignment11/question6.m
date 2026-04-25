%Q6. Print the multiplication and addition table of an inputted number. i.e  
%    multiplication table	addition table
%    5*1=5	                0+5=5
%    5*2=10	                1+4=5
%    5*3=15	                2+3=5
%    5*4=20	                3+2=5
%    5*5=25	                4+1=5
%    5*6=30	                5+0=5

n = input('Enter number: ');

for i = 1:6
    fprintf('%d * %d = %d\t', n, i, n * i);
    fprintf('%d + %d = %d\n', i - 1, n - (i - 1), n);
end
