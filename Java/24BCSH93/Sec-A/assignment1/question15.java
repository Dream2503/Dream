// Q15. Write a java program  to determine whether the number is a palindrome

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        int temp = num;
        int reversed = 0;

        while (temp != 0) {
            reversed = reversed * 10 + (temp % 10);
            temp /= 10;
        }
        if (num == reversed) {
            System.out.println(num + " is a palindrome");
        } else {
            System.out.println(num + " is not a palindrome");
        }
    }
}
