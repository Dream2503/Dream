/*  Q7. Given a sorted array, remove the duplicate elements from the array.
        Input: size of the array(n) and n numbers (the elements of the array).
        You are supposed to output the size of the new array followed by the elements of the new array after removing duplicates.
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = createArray();
        displayArray(array, array.length);
        int newSize = removeDuplicates(array);
        System.out.println("Array after removing duplicates");
        displayArray(array, newSize);
    }

    private static int removeDuplicates(int[] array) {
        int i = 0;

        for (int j = 0; j < array.length; j++) {
            if (array[i] != array[j]) {
                array[++i] = array[j];
            }
        }
        return i + 1;
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

    private static void displayArray(int[] array, int n) {
        System.out.print("The array elements are: ");

        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
