//  Q6. Write a program to input the marks of a student in three different subjects and then display the average mark.

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
        double average = (english + maths + science) / 3;
        System.out.println("The average marks in 3 subjects is :" + average);
    }
}
