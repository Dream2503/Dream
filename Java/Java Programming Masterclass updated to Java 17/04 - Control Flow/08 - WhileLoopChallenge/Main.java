public class Main {
    public static void main(String[] args) {
        int number = 4, finishNumber = 20, evenCount = 0, oddCount = 0;

        while (number <= finishNumber) {
            number++;

            if (!isEvenNumber(number)) {
                oddCount++;
                continue;
            }
            System.out.println("Even Number " + number);
            evenCount++;

            if (evenCount >= 5) {
                break;
            }
        }
        System.out.println("Total odd numbers found = " + oddCount);
        System.out.println("Total even numbers found = " + evenCount);
    }

    public static boolean isEvenNumber(int number) {
        if (number % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
}