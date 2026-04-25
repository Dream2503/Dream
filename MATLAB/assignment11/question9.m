%Q9. Print the following pattern on the screen.
%    *
%    * *
%    * * *
%    * * * *
%    * * * * *

for i = 1:5
    for j = 1:i
        fprintf('* ');
    end
    fprintf('\n');
end
