//  Q5. Write a java program that will take variable number of arguments.

class Main {
    public static void main(String[] args) {
        System.out.print("The variable number of arguments that were accepted are: ");

        for (String arg : args) {
            System.out.print(arg + " ");
        }
    }
}