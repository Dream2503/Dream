//	Q8. Write a program to input a jagged array and display it.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int row = sc.nextInt();
        int[][] jaggedArray = new int[row][];
        System.out.print("Enter jagged column for each row: ");

        for (int i = 0; i < row; i++) {
            int col = sc.nextInt();
            jaggedArray[i] = new int[col];
        }
        System.out.println("Enter the elements of jagged array:");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < jaggedArray[i].length; j++) {
                jaggedArray[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the elements in jagged array are:");

        for (int[] array : jaggedArray) {
            for (int element : array) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
}
