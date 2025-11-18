//	Q4. Write a program that performs the addition of two numbers using command-line arguments.

class Main {
    public static void main(String[] args) {
        int num1 = Integer.parseInt(args[0]);
        int num2 = Integer.parseInt(args[1]);
        int res = num1 + num2;
        System.out.println("The sum of " + num1 + " and " + num2 + " is: " + res);
    }
}
