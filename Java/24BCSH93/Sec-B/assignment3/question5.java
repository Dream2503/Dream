/*	Q5. Write a program that will take two integer numbers from the command prompt and find their GCD. If the user does not provide exactly two
        numbers of arguments then the program should display error message
*/

class Main {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Provide exactly two command line argument");
            return;
        }
        int num1 = Integer.parseInt(args[0]);
        int num2 = Integer.parseInt(args[1]);
        int a = num1, b = num2;

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        System.out.println("The gcd of " + num1 + " and " + num2 + " is: " + a);
    }
}
