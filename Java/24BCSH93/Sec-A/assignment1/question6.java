/*  Q6. Write a Java program that will evaluate the exponential series.
           i.e. e^x = 1 + x + x^2/2! + x^3/3! + ...
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the exponent: ");
        double x = sc.nextDouble();
        System.out.print("Enter the no. of iterations:");
        int itr = sc.nextInt();
        double ex = 1;

        for (int i = itr - 1; i > 0; i--) {
            ex = 1 + (x / i) * ex;
        }
        System.out.println("e^" + x + " = " + ex);
    }
}
