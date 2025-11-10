/*	Q2. Write a JAVA program to capitalize first letter of each word in an inputted sentence from keyboard.
        Sample Output:
        Enter a sentence: india is great
        India Is Great
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String string = sc.nextLine();
        StringBuilder stringBuilder = new StringBuilder(string.length() + 1);

        for (String word : string.split(" ")) {
            stringBuilder.append(Character.toUpperCase(word.charAt(0))).append(word.substring(1)).append(' ');
        }
        System.out.println("Transformed String is: " + stringBuilder);
    }
}
