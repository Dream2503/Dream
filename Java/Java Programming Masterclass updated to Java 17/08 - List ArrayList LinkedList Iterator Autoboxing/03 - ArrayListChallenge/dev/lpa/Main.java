package dev.lpa;

import java.util.*;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean flag = true;
        ArrayList<String> groceries = new ArrayList<>();

        while (flag) {
            printActions();

            switch (Integer.parseInt(scanner.nextLine())) {
                case 1 -> addItems(groceries);
                case 2 -> removeItems(groceries);
                default -> flag = false;
            }
            groceries.sort(Comparator.naturalOrder());
            System.out.println(groceries);
        }
    }

    private static void addItems(ArrayList<String> groceries) {
        System.out.println("Add item(s) [seperated items by comma]:");
        String[] items = scanner.nextLine().split(", ");
//        groceries.addAll(List.of(items));

        for (String i : items) {
            if (!groceries.contains(i)) {
                groceries.add(i);
            }
        }
    }

    private static void removeItems(ArrayList<String> groceries) {
        System.out.println("Remove item(s) [seperated items by comma]:");
        String[] items = scanner.nextLine().split(", ");
        groceries.removeAll(List.of(items));
    }

    private static void printActions() {
        String textBlock = """
                Available actions:
                
                0 - to shutdown
                
                1 - to add item(s) to list (comma delimited list)
                
                2 - to remove any items (comma delimited list)
                
                Enter a number for which action you want to do:""";
        System.out.print(textBlock + " ");
    }
}
