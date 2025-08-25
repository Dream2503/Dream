//  Q5. Write a java program that to perform multiplication of two matrix.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        System.out.println("Matrix1");
        int[][] mat1 = createMatrix();
        displayMatrix(mat1);
        System.out.println("\nMatrix2");
        int[][] mat2 = createMatrix();
        displayMatrix(mat2);
        System.out.println("\nResult");
        int[][] res = matMul(mat1, mat2);
        displayMatrix(res);
    }

    private static int[][] matMul(int[][] mat1, int[][] mat2) {
        if (mat1[0].length != mat2.length) {
            System.out.println("Incorrect matrix dimension for multiplication");
            System.exit(0);
        }
        int[][] res = new int[mat1.length][mat2[0].length];

        for (int k = 0; k < mat1.length; k++) {
            for (int i = 0; i < mat2[0].length; i++) {
                for (int j = 0; j < mat1[0].length; j++) {
                    res[k][i] += mat1[k][i] * mat2[j][i];
                }
            }
        }
        return res;
    }

    private static int[][] createMatrix() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the dimension of first matrix: ");
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] matrix = new int[row][col];
        System.out.print("Enter the matrix elements: ");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        return matrix;
    }

    private static void displayMatrix(int[][] matrix) {
        System.out.print("The matrix elements are: ");

        for (int[] row : matrix) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
}
