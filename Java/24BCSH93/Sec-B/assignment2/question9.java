//  Q9. Write a program to display all Armstrong numbers from 1 to 10000.

class Main {
    public static void main(String[] args) {
        System.out.println("The armstrong numbers between 1 and 10000 are ");

        for (int num = 1; num <= 10000; num++) {
            int pow = (int) Math.log10(num) + 1;
            int temp = num, armstrong = 0;

            while (temp != 0) {
                armstrong += (int) Math.pow(temp % 10, pow);
                temp /= 10;
            }
            if (armstrong == num) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }
}
