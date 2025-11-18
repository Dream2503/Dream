/*	Q5. Create an interface Servicing that has abstract methods getServiceTime(). Create two class Car, Bike that implement interface. Create a Main
		class that creates the objects of two class and displays the service time.
*/

interface Servicing {
    void getServiceTime();
}

class Car implements Servicing {
    public void getServiceTime() {
        System.out.println("Servicing time for Car is: 9 AM");
    }
}

class Bike implements Servicing {
    public void getServiceTime() {
        System.out.println("Servicing time for Bike is: 10 AM");
    }
}

class Main {
    public static void main(String[] args) {
        (new Car()).getServiceTime();
        (new Bike()).getServiceTime();
    }
}