/*  Q6. Create the classes as given in the below figure. Display the interest rate in the following format:
        SBI Rate of Interest : 8
        ICICI Rate of Interest : 7
        AXIS Rate of Interest : 9
*/

abstract class Bank {
    abstract double getRateOfInterest();
}

class SBI extends Bank {
    public double getRateOfInterest() {
        return 8.0;
    }
}

class ICICI extends Bank {
    public double getRateOfInterest() {
        return 7.0;
    }
}

class AXIS extends Bank {
    public double getRateOfInterest() {
        return 9.0;
    }
}

class Main {
    public static void main(String[] args) {
        Bank bank;
        bank = new SBI();
        System.out.println("SBI Rate of Interest: " + bank.getRateOfInterest());
        bank = new ICICI();
        System.out.println("ICICI Rate of Interest: " + bank.getRateOfInterest());
        bank = new AXIS();
        System.out.println("AXIS Rate of Interest: " + bank.getRateOfInterest());
    }
}
