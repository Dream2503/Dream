//  Q4. Write a program to illustrate the use of multiple catch blocks associated with a single try block.

class Main {
    public static void main(String[] args) {
        try {
            int numerator = Integer.parseInt(args[0]);
            int denominator = Integer.parseInt(args[1]);
            int quotient = numerator / denominator;
            System.out.println(numerator + " / " + denominator + " = " + quotient);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Pass atleast 2 command line arguments");
        } catch (NumberFormatException e) {
            System.out.println("Enter valid number containing digits");
        } catch (ArithmeticException e) {
            System.out.println("Division by zero occurred");
        }
    }
}
