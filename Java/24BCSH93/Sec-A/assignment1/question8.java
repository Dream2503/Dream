// Q8. Write a java program that will count the number of primes between 37 and 129.

class Main {
    public static void main(String[] args) {
        int composite = 0;

        for (int num = 37; num <= 129; num++) {
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    composite++;
                    break;
                }
            }
        }
        int prime = (129 - 37 + 2) - composite;
        System.out.println("Total number of primes in between 37 and 129 is " + prime);
    }
}
