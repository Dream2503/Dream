public class Main {
    public static void main(String[] args) {
//        Account bobsAccount = new Account(12345, 1000.00, "Bob Brown", "myemail@bob.com", "(087) 123-4567");
        Account bobsAccount = new Account();

        System.out.println(bobsAccount.getAccountNumber());
        System.out.println(bobsAccount.getAccountBalance());

//        bobsAccount.setAccountNumber(12345);
//        bobsAccount.setAccountBalance(1000.00);
//        bobsAccount.setCustomerName("Bob Brown");
//        bobsAccount.setEmail("myemail@bob.com");
//        bobsAccount.setPhoneNumber("(087) 123-4567");

        bobsAccount.withdraw(100);
        bobsAccount.deposit(250);
        bobsAccount.withdraw(50);

        bobsAccount.withdraw(200);
        bobsAccount.deposit(100);
        bobsAccount.withdraw(45.55);
        bobsAccount.withdraw(54.46);
        bobsAccount.withdraw(54.45);

        Account timsAccount = new Account("Tim", "time@email.com", "12345");
        System.out.println("Account number: " + timsAccount.getAccountNumber() + "; name " + timsAccount.getCustomerName());
    }
}