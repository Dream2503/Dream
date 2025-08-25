//  Q6. Write a java program, that will read a matrix, identify if the matrix is symmetric or not.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[][] matrix = createMatrix();
        displayMatrix(matrix);

        if (isSymmetric(matrix)) {
            System.out.println("The matrix is a symmetric matrix");
        } else {
            System.out.println("The matrix is not a symmetric matrix");
        }
    }

    private static boolean isSymmetric(int[][] matrix) {
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 0; j < i; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
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
