import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, num;
        String input;

        do {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter number or 'exit' to quit: ");
            input = sc.nextLine();

            if (!input.equals("exit")) {
                try {
                    num = Integer.parseInt(input);

                    if (num > max) {
                        max = num;
                    }
                    if (num < min) {
                        min = num;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input");
                }
            }
        } while (!input.equals("exit"));

        System.out.println("Minimum Number: " + min);
        System.out.println("Maximum Number: " + max);
    }
}