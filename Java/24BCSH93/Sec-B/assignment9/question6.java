//  Q6. Write a program that computes your initials from your full name and displays them.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your full name: ");
        String string = sc.nextLine();
        String[] words = string.split(" ");
        StringBuilder stringBuilder = new StringBuilder(words.length);

        for (String word : words) {
            stringBuilder.append(Character.toUpperCase(word.charAt(0)));
        }
        System.out.println("Initials String is: " + stringBuilder);
    }
}
