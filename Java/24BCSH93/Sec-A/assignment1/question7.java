/*  7. Write a Java program that will evaluate the sin(x) series. (Hints Use Taylor series expansion)
           i.e. sin(x) = x – x^3/3! + x^5/5! -  ...
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the sin argument: ");
        double x = sc.nextDouble();
        System.out.print("Enter the no. of iterations:");
        int itr = sc.nextInt();
        double sinx = 1;

        for (int k = itr; k > 0; k--) {
            int i = 2 * k;
            sinx = 1 - (x * x) / (i * (i + 1)) * sinx;
        }
        System.out.println("sin(" + x + ") = " + sinx * x);
    }
}
