/*	Q2. Write a java program that will create a thread and set the thread name, display the thread name, get the thread id, check the thread is
		currently alive or not.
*/

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Thread thread = new Thread();
        System.out.print("Enter the Thread name to set: ");
        thread.setName(sc.next());
        System.out.println("Thread ID: " + thread.threadId());
        System.out.println("Thread is alive?: " + thread.isAlive());
    }
}
