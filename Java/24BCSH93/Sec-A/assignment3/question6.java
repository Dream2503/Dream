/*	Q6. Define a class Stack, which has the member function to perform basic operation of stack. Define another main class to demonstrate the basic
        operation.
 */

import java.util.Scanner;

class Stack {
    private int[] stack;
    private int top;

    public Stack(int size) {
        stack = new int[size];
        top = -1;
    }

    public void push(int value) {
        if (top == stack.length - 1) {
            System.out.println("Stack Overflow");
        } else {
            stack[++top] = value;
        }
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
            return -1;
        } else {
            return stack[top--];
        }
    }

    public void display() {
        if (top == -1) {
            System.out.println("The stack is currently empty");
        } else {
            System.out.print("The stack contains: ");

            for (int i = 0; i <= top; i++) {
                System.out.print(stack[i] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of stack to initialize: ");
        int size = sc.nextInt();
        Stack stack = new Stack(size);

        while (true) {
            System.out.println("    Menu for Stack");
            System.out.println("1. Push an element");
            System.out.println("2. Pop an element");
            System.out.println("0. To exit");
            System.out.print("Enter your choice: ");
            int ch = sc.nextInt();
            int element;

            switch (ch) {
                case 0:
                    return;

                case 1:
                    System.out.println("Enter an element to push to the stack: ");
                    element = sc.nextInt();
                    stack.push(element);
                    stack.display();
                    break;

                case 2:
                    element = stack.pop();

                    if (element != -1) {
                        System.out.println("Popped " + element + " from the stack");
                    }
                    stack.display();
                    break;

                default:
                    System.out.println("Invalid input. Try again...");
            }
        }
    }
}
