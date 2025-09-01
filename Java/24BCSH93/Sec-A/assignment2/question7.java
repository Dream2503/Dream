/*  Q7. Given a sorted array, remove the duplicate elements from the array.
        Input: size of the array(n) and n numbers (the elements of the array).
        You are supposed to output the size of the new array followed by the elements of the new array after removing duplicates.
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] array = new int[n];
        System.out.print("Enter the array elements: ");

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (array[i] != array[j]) {
                array[++i] = array[j];
            }
        }
        int newSize = i + 1;
        System.out.print("The array elements after removing duplicates are: ");

        for (int j = 0; j < newSize; j++) {
            System.out.print(array[j] + " ");
        }
        System.out.println();
    }
}
