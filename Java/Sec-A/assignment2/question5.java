//  Q5. Write a java program that to perform multiplication of two matrix.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[][] matrix1 = createMatrix("first matrix");
        int[][] matrix2 = createMatrix("second matrix");

        if (matrix1[0].length != matrix2.length) {
            System.out.println("Invalid matrix dimensions for multiplication");
            System.exit(0);
        }
        int[][] res = new int[matrix1.length][matrix2[0].length];

        for (int k = 0; k < matrix1.length; k++) {
            for (int i = 0; i < matrix2[0].length; i++) {
                for (int j = 0; j < matrix1[0].length; j++) {
                    res[k][i] += matrix1[k][i] * matrix2[j][i];
                }
            }
        }
        System.out.println("The resultant matrix elements are:");

        for (int[] array : res) {
            for (int element : array) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }

    private static int[][] createMatrix(String name) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the dimensions of the " + name + ": ");
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] matrix = new int[row][col];
        System.out.println("Enter the " + name + " elements:");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        return matrix;
    }
}
