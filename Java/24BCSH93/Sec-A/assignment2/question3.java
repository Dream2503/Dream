//  Q3. Write a java program that to perform binary search.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = createArray();
        displayArray(array);
        System.out.print("Enter the element to search in the array: ");
        int key = sc.nextInt();
        int pos = binarySearch(array, key);

        if (pos == -1) {
            System.out.println(key + " was not found in the array");
        } else {
            System.out.println(key + " was found at index " + pos + " in the array");
        }
    }

    private static int binarySearch(int[] array, int key) {
        int low = 0, high = array.length, mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (array[mid] > key) {
                high = mid - 1;
            } else if (array[mid] < key) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
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
