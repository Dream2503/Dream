/*  Q2. From the previous assignment add some members, which are protected and private. Check that , which modifier accessible, outside of the
        package.
*/

import dream.UpdatedTest;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the values of i, j, k for Test1: ");
        int i = sc.nextInt();
        int j = sc.nextInt();
        int k = sc.nextInt();
        UpdatedTest updatedTest = new UpdatedTest(i, j, k);
        updatedTest.show();

        System.out.println("updatedTest.i = " + updatedTest.i);
//        System.out.println(updatedTest.x); // private
//        System.out.println(updatedTest.y); // protected
    }
}
