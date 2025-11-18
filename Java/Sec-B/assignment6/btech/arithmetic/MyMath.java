package btech.arithmetic;

public class MyMath {
    public static double add(double lhs, double rhs) {
        return lhs + rhs;
    }

    public static double sub(double lhs, double rhs) {
        return lhs - rhs;
    }

    public static double mul(double lhs, double rhs) {
        return lhs * rhs;
    }

    public static double div(double lhs, double rhs) {
        validate(rhs);
        return lhs / rhs;
    }

    public static double mod(double lhs, double rhs) {
        validate(rhs);
        return lhs % rhs;
    }

    private static void validate(double value) {
        if (value == 0) {
            System.out.println("Division by Zero");
            System.exit(0);
        }
    }
}
