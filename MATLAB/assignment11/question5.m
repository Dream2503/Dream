%Q5. Input the mark of 5 subject of a student. Print the grade based on the average marks. (.Solve using switch case only) 
%    Average>=60……………………….1st   division.
%    Average>=50 and Average<60…….2nd division
%    Average>=30 and Average<50…….3rd division
%    Average<30………………………  fail

marks = zeros(1, 5);

for i = 1:5
    marks(i) = input(['Enter marks for subject ', num2str(i), ': ']);
end
avg = mean(marks);

switch true
    case avg >= 60
        disp('1st Division')
    case avg >= 50
        disp('2nd Division')
    case avg >= 30
        disp('3rd Division')
    otherwise
        disp('Fail')
end
