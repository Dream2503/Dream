/*  Q1. Write a program to print the average of three numbers entered by user by creating a class named 'Average' having a method to calculate
        and print the average. Define another Main class to demonstrate the basic operation.
*/

import java.util.Scanner;

class Average {
    public static double calculateAverage(double a, double b, double c) {
        return (a + b + c) / 3.0;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 3 numbers: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        double avg = Average.calculateAverage(a, b, c);
        System.out.println("The average of 3 numbers is " + avg);
    }
}
