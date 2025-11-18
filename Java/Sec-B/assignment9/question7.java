//  Q7. Write a program that receives two strings and check whether they are equal or not.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String: ");
        String string1 = sc.next();
        System.out.print("Enter a String: ");
        String string2 = sc.next();

        if (string1.equals(string2)) {
            System.out.println(string1 + " and " + string2 + " are equal");
        } else {
            System.out.println(string1 + " and " + string2 + " are not equal");
        }
    }
}
