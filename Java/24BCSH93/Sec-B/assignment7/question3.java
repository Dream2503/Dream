/*  Q3. Write an exception handling java program to print the index position of an existing integer array. The index value will be entered by user. It
        will be handled by exception handler if index position is greater than the size of array. In the exception handler the program should display
        appropriate message to the user.
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int[] array = new int[sc.nextInt()];
        System.out.print("Enter the index of the array to peek: ");
        int idx = sc.nextInt();

        try {
            System.out.println("The value at " + idx + " in the array is: " + array[idx]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }
    }
}