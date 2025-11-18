//	Q4. Write a Java program to input a string and print the total number of characters present in the string.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String: ");
        System.out.println("Total number of characters present: " + sc.nextLine().length());
    }
}
