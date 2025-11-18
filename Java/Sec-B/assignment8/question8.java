//	Q8. Write a java program that will create two threads. Set the priority to each thread and display it.

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Thread thread1 = new Thread();
        Thread thread2 = new Thread();

        System.out.print("Enter the Priority of First Thread: ");
        thread1.setPriority(sc.nextInt());
        System.out.print("Enter the Priority of Second Thread: ");
        thread2.setPriority(sc.nextInt());

        System.out.println("First Thread Priority: " + thread1.getPriority());
        System.out.println("Second Thread Priority: " + thread2.getPriority());
    }
}