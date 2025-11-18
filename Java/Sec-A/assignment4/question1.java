//  Q1. Write a Java program to find the sum of any number of integers provided as command-line arguments.

class Main {
    public static void main(String[] args) {
        int sum = 0;

        for (String arg : args) {
            sum += Integer.parseInt(arg);
        }
        System.out.println("The sum of all the integers provided is " + sum);
    }
}