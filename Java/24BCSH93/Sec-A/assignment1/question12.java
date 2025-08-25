//  Q12. Given a number N. Write a program that find the number of co-prime pairs (a, b) from 1 to N such that their product(a*b) is equal to N.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        int cnt = 0, j;

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                j = num / i;

                if (i < j && gcd(i, j) == 1) {
                    cnt++;
                }
            }
        }
        System.out.println("Total number of co-primes pair from 1 to " + num + " whose product is equal to " + num + " is " + cnt);
    }

    private static int gcd(int num1, int num2) {
        while (num2 != 0) {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
}
