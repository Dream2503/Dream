//  Q4. Write a Java program to test the inputted number is prime or composite.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                System.out.println(num + " is a composite number");
                return;
            }
        }
        System.out.println(num + " is a prime number");
    }
}
