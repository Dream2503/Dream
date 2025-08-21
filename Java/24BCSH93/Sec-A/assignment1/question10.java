/*  Q10. Write a java program that will print the following patterns
             *
           * * *
         * * * * *
       * * * * * * *
     * * * * * * * * *
 */

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        for (int i = 1; i <= num; i++) {
            for (int j = i + 1; j <= num; j++) {
                System.out.print("  ");
            }
            for (int j = 1; j <= (i * 2) - 1; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
