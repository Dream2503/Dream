//  Q6. Write a java program, that will read a matrix, identify if the matrix is symmetric or not.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the dimensions of the matrix: ");
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] matrix = new int[row][col];
        System.out.println("Enter the matrix elements:");

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        if (row == col) {
            for (int i = 1; i < matrix.length; i++) {
                for (int j = 0; j < i; j++) {
                    if (matrix[i][j] != matrix[j][i]) {
                        System.out.println("The matrix is not a symmetric matrix");
                        return;
                    }
                }
            }
        }
        System.out.println("The matrix is a symmetric matrix");
    }
}
