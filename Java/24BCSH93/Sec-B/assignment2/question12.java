//	Q12. Write a recursive program to find the sum of n natural numbers. [n is user input]

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        System.out.println("The sum of first " + n + " natural numbers is " + sum(n));
    }

    private static int sum(int n) {
        if (n == 0) {
            return n;
        }
        return n + sum(n - 1);
    }
}
