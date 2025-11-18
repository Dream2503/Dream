/*	Q2. Write a program to enter the marks of a student in 4 different subjects. Then display the grade of the student as per the following
       conditions:
		a. If the average mark is greater than or equal to 90 then grade is O
		b. If the average mark is greater than equal to 80 but less than 90 then grade is E
		c. If the average mark is greater than equal to 70 but less than 80 then grade is A
		d. If the average mark is greater than equal to 60 but less than 70 then grade is B
		e. If the average mark is greater than equal to 50 but less than 60 then grade is C
		f. If the average mark is less than 50 then grade is F
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your marks in English: ");
        double english = sc.nextDouble();
        System.out.print("Enter your marks in Maths: ");
        double maths = sc.nextDouble();
        System.out.print("Enter your marks in Science: ");
        double science = sc.nextDouble();
        System.out.print("Enter your marks in Computer: ");
        double computer = sc.nextDouble();
        double average = (english + maths + science + computer) / 4;
        String grade;

        if (average > 90) {
            grade = "O";
        } else if (average > 80) {
            grade = "E";
        } else if (average > 70) {
            grade = "A";
        } else if (average > 60) {
            grade = "B";
        } else if (average > 50) {
            grade = "C";
        } else {
            grade = "F";
        }
        System.out.println("Your grade is " + grade);
    }
}
