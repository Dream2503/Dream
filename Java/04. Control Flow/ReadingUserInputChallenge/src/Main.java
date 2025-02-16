import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int cnt = 0;
        double sum = 0;

        do {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter number #" + (cnt + 1) + ": ");

            try {
                sum += Double.parseDouble(scanner.nextLine());
                cnt++;
            } catch (NumberFormatException e) {
                System.out.println("Invalid number");
            }
        } while (cnt < 5);

        System.out.println("The sum of the 5 numbers = " + sum);
    }
}