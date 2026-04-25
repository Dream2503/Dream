%Q10. Input User name and password and validate it. Allow the user for input 3 times if any wrong input is there. 

correct_user = 'admin';
correct_pass = '1234';

for i = 1:3
    user = input('Enter username: ', 's');
    pass = input('Enter password: ', 's');

    if strcmp(user, correct_user) && strcmp(pass, correct_pass)
        disp('Login successful');
        break;
    else
        disp('Wrong credentials');
    end
    if i == 3
        disp('Access denied');
    end
end
