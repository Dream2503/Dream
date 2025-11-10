//  Q5. Write a java program to replace a substring with another string.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String: ");
        String string = sc.nextLine();
        System.out.print("Enter the Sub-String: ");
        String subString = sc.nextLine();
        System.out.print("Enter the String to replace with: ");
        String replaceWith = sc.nextLine();
        System.out.println("String after sub-string replacement: " + string.replace(subString, replaceWith));
    }
}
