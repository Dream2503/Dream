//  Q5. Write a java program that will compute GCD and LCM of two inputted numbers.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int gcd = 0;

        for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
                gcd = i;
            }
        }
        int lcm = num1 * num2 / gcd;
        System.out.println(gcd + " is the gcd and " + lcm + " is the lcm of " + num1 + " and " + num2);
    }
}
