//	Q1. Write a JAVA program to read a string from the key board and print its reverse. Also check whether the string is palindrome or not.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String: ");
        String string = sc.next();
        StringBuilder reversed = new StringBuilder(string).reverse();
        System.out.println("Reversed String is: " + reversed);

        if (string.contentEquals(reversed)) {
            System.out.println(string + " is a palindrome");
        } else {
            System.out.println(string + " is not a palindrome");
        }
    }
}
