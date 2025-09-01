//	Q3. Write a program input two matrices and perform the addition of two matrices.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the dimensions of the matrix: ");
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] matrix1 = createMatrix("first matrix", row, col);
        int[][] matrix2 = createMatrix("second matrix", row, col);
        int[][] res = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        System.out.println("The resultant matrix elements are:");

        for (int[] array : res) {
            for (int element : array) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static int[][] createMatrix(String name, int row, int col) {
        Scanner sc = new Scanner(System.in);
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
