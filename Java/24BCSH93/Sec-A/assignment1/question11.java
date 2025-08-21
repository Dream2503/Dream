/*  Q11. Write a program that find all the numbers that are coprime to a given number N and less than N.
    (Note: A pair(a, b) is said to be co-prime if gcd(a, b) = 1)
*/

import java.util.Scanner;

class Main {
    public static int gcd(int num1, int num2) {
        while (num2 != 0) {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        System.out.print("All the co-primes of " + num + " and less than " + num + " are ");

        for (int i = 1; i < num; i++) {
            if (gcd(i, num) == 1)  {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}
