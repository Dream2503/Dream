/*  Q1. Write a program to calculate tax, given the following conditions:
        a. If income is less than 150000 then no tax
        b. If taxable income is in the range 150001 to 300000 then charge 10% tax
        c. If taxable income is in the range 300001 to 500000 then charge 20% tax
        d. If taxable income is above 500001 then charge 30% tax
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your income: ");
        double income = sc.nextDouble();
        double taxRate;

        if (income > 500000) {
            taxRate = income * 0.3;
        } else if (income > 300000) {
            taxRate = income * 0.2;
        } else if (income > 150000) {
            taxRate = income * 0.1;
        } else {
            taxRate = 0;
        }
        System.out.println("Your calculated tax on the income is " + taxRate);
    }
}
