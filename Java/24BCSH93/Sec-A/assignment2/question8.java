/*  Q8. Given an array which contains both positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum. What is a
        subarray? Well, a subarray is a contiguous part of array. An array that is inside another array. For example, consider the array [1, 2, 3, 4],
        There are 10 non-empty sub-arrays. The sub-arrays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4). In the first
        line, you are given an integer n (size of the array) as input. In the second line you are given n numbers (the elements of the array). You
        are supposed to output true in case there is a subarray (of size at-least one) with 0 sum else output false.
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
        int sum;

        for (int i = 0; i < n; i++) {
            sum = 0;

            for (int j = i; j < n; j++) {
                sum += array[j];

                if (sum == 0) {
                    System.out.println(true);
                    return;
                }
            }
        }
        System.out.println(false);
    }
}
