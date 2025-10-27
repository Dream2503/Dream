/*  Q1. Create a java package by your name. The package should contain the class Test
        i.
        class Test {
            public int i;

            //Define the constructor and initialize all the data members.

            public void show(){
                -------
            }
        }

        ii.  Include another class into the same package
        The package should contain the class
        class Test1 {
            public int i;
            int j
            protected k;

            //Define the constructor and initialize all the data members.

            void show(){
                ..................
            }
        }
*/

import dream.Test;
import dream.Test1;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of i for Test: ");
        Test test = new Test(sc.nextInt());
        System.out.print("Enter the values of i, j, k for Test1: ");
        int i = sc.nextInt();
        int j = sc.nextInt();
        int k = sc.nextInt();
        Test1 test1 = new Test1(i, j, k);
        test.show();
//        test1.show(); // not accessible [package-private modifier]
    }
}
