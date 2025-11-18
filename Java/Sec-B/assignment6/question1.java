/*	Q1. Create a abstract class Bank that has abstract method getROI(). Create three classes SBI, PNB, BOI inherited from Bank. Create a Main class
		that prints the rate of interest of each bank using super class memory reference.
*/

abstract class Bank {
    public abstract double getROI();
}

class SBI extends Bank {
    public double getROI() {
        return 8.0;
    }
}

class PNB extends Bank {
    public double getROI() {
        return 7.0;
    }
}

class BOI extends Bank {
    public double getROI() {
        return 9.0;
    }
}

class Main {
    public static void main(String[] args) {
        Bank bank;
        bank = new SBI();
        System.out.println("Rate of Interest of SBI: " + bank.getROI());
        bank = new PNB();
        System.out.println("Rate of Interest of PNB: " + bank.getROI());
        bank = new BOI();
        System.out.println("Rate of Interest of BOI: " + bank.getROI());
    }
}
