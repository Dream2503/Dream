//  Q4. Write a java program that will perform scalar product of two vectors.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        System.out.println("Vector1");
        int[] vec1 = createArray();
        displayArray(vec1);
        System.out.println("\nVector2");
        int[] vec2 = createArray();
        displayArray(vec2);
        int res = scalarProduct(vec1, vec2);
        System.out.println("\nThe scalar product of the two vectors is " + res);
    }

    private static int scalarProduct(int[] vec1, int[] vec2) {
        if (vec1.length != vec2.length) {
            System.out.println("Cannot determine the scalar product of different dimension of vectors");
            System.exit(0);
        }
        int res = 0;

        for (int i = 0; i < vec1.length; i++) {
            res += vec1[i] * vec2[i];
        }
        return res;
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
