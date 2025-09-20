/*  Q2. Write a Java program to compute the GCD (Greatest Common Divisor) of two numbers, where the numbers are provided as command-line arguments.
        If fewer than two arguments are passed, the program should display an appropriate error message.
*/

class Main {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Exactly 2 command-line arguments were not passed");
            System.exit(0);
        }
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        System.out.println("The GCD of " + args[0] + " and " + args[1] + " is " + a);
    }
}