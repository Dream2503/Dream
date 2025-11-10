//	Q3. Write a JAVA program to convert a string into uppercase.

import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a String: ");
		System.out.println("Upper-Case String is: " + sc.nextLine().toUpperCase());
	}
}
