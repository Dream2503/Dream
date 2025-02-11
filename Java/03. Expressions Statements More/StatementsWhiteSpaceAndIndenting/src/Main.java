public class Main {
    public static void main(String[] args) {
        int myVariable = 50;
        myVariable++;
        myVariable--;

        System.out.println("This is a test");
        System.out.println("This is" +
                " another" +
                " still more.");

        int anotherVariable = 50;
        myVariable--;
        System.out.println("myVariable = " + myVariable);

        if (myVariable == 0) {
            System.out.println("It's now zero");
        }
    }
}