//  Q1. Write a java program that will create a one-dimensional array of integer and display the elements of the array.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[] array = createArray();
        displayArray(array);
    }

    private static int[] createArray() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] array = new int[n];
        System.out.print("Enter the array elements: ");

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        return array;
    }

    private static void displayArray(int[] array) {
        System.out.print("The array elements are: ");

        for (int element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}
