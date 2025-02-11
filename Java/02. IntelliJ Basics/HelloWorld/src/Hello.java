//public class Hello {
//    public static void main(String[] args) {
//        System.out.print("Hello World");
//    }
//}


//public class Hello {
//    public static void main(String[] args) {
//        System.out.println("Hello, Dream");
//        System.out.print("Hello World");
//    }
//}


//public class Hello {
//    public static void main(String[] args) {
//        System.out.println("Hello, Dream");
//
//        boolean isAlien = false;
//        if (isAlien == false) {
//            System.out.println("It is not an alien!");
//            System.out.println("And I am scared of aliens");
//        }
//    }
//}


//public class Hello {
//    public static void main(String[] args) {
//        System.out.println("Hello, Dream");
//
//        boolean isAlien = false;
//        if (isAlien == false) {
//            System.out.println("It is not an alien!");
//            System.out.println("And I am scared of aliens");
//        }
//
//        int topScore = 80;
//        if (topScore < 100) {
//            System.out.println("You got the high score!");
//        }
//
//        int secondTopScore = 81;
//        if ((topScore > secondTopScore) && (topScore < 100)) {
//            System.out.println("Greater than second top score and less than 100");
//        }
//    }
//}


//public class Hello {
//    public static void main(String[] args) {
//        System.out.println("Hello, Dream");
//
//        boolean isAlien = false;
//        if (isAlien == false) {
//            System.out.println("It is not an alien!");
//            System.out.println("And I am scared of aliens");
//        }
//
//        int topScore = 80;
//        if (topScore < 100) {
//            System.out.println("You got the high score!");
//        }
//
//        int secondTopScore = 81;
//        if ((topScore > secondTopScore) && (topScore < 100)) {
//            System.out.println("Greater than second top score and less than 100");
//        }
//
//        if ((topScore > 90) || (secondTopScore <= 90)) {
//            System.out.println("Either or both the conditions are true");
//        }
//    }
//}


//public class Hello {
//    public static void main(String[] args) {
//        System.out.println("Hello, Dream");
//
//        boolean isAlien = false;
//        if (isAlien == false) {
//            System.out.println("It is not an alien!");
//            System.out.println("And I am scared of aliens");
//        }
//
//        int topScore = 80;
//        if (topScore < 100) {
//            System.out.println("You got the high score!");
//        }
//
//        int secondTopScore = 81;
//        if ((topScore > secondTopScore) && (topScore < 100)) {
//            System.out.println("Greater than second top score and less than 100");
//        }
//
//        if ((topScore > 90) || (secondTopScore <= 90)) {
//            System.out.println("Either or both the conditions are true");
//        }
//
//        int newValue = 50;
//        if (newValue == 50) {
//            System.out.println("This is true");
//        }
//
//        boolean isCar = false;
//        if (!isCar) {
//            System.out.println("This is not supposed to happen");
//        }
//    }
//}


//public class Hello {
//    public static void main(String[] args) {
//        System.out.println("Hello, Dream");
//
//        boolean isAlien = false;
//        if (isAlien == false) {
//            System.out.println("It is not an alien!");
//            System.out.println("And I am scared of aliens");
//        }
//
//        int topScore = 80;
//        if (topScore < 100) {
//            System.out.println("You got the high score!");
//        }
//
//        int secondTopScore = 81;
//        if ((topScore > secondTopScore) && (topScore < 100)) {
//            System.out.println("Greater than second top score and less than 100");
//        }
//
//        if ((topScore > 90) || (secondTopScore <= 90)) {
//            System.out.println("Either or both the conditions are true");
//        }
//
//        int newValue = 50;
//        if (newValue == 50) {
//            System.out.println("This is true");
//        }
//
//        boolean isCar = false;
//        if (!isCar) {
//            System.out.println("This is not supposed to happen");
//        }
//
//        String makeOfCar = "Volkswagen";
//        boolean isDomestic = makeOfCar == "Volkswagen" ? false : true;
//
//        if (isDomestic) {
//            System.out.println("This car is domestic in out country");
//        }
//
//        String s = (isDomestic) ? "This car is domestic" : "This car is not domestic";
//        System.out.println(s);
//    }
//}


public class Hello {
    public static void main(String[] args) {
        System.out.println("Hello, Dream");

        boolean isAlien = false;
        if (isAlien == false) {
            System.out.println("It is not an alien!");
            System.out.println("And I am scared of aliens");
        }

        int topScore = 80;
        if (topScore < 100) {
            System.out.println("You got the high score!");
        }

        int secondTopScore = 81;
        if ((topScore > secondTopScore) && (topScore < 100)) {
            System.out.println("Greater than second top score and less than 100");
        }

        if ((topScore > 90) || (secondTopScore <= 90)) {
            System.out.println("Either or both the conditions are true");
        }

        int newValue = 50;
        if (newValue == 50) {
            System.out.println("This is true");
        }

        boolean isCar = false;
        if (!isCar) {
            System.out.println("This is not supposed to happen");
        }

        String makeOfCar = "Volkswagen";
        boolean isDomestic = makeOfCar == "Volkswagen" ? false : true;

        if (isDomestic) {
            System.out.println("This car is domestic in out country");
        }

        String s = (isDomestic) ? "This car is domestic" : "This car is not domestic";
        System.out.println(s);

        double step1 = 20.00d, step2 = 80.00d;
        double step3 = (step1 + step2) * 100.00d;
        double step4 = step3 % 40.00d;
        boolean step5 = step4 == 0;
        System.out.println(step5);

        if (!step5) {
            System.out.println("Got some remainder");
        }
    }
}   