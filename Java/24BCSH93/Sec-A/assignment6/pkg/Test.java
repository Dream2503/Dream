package pkg;

public class Test {
    int defaultVar = 30;
    private int privateVar = 40;
    protected int protectedVar = 20;
    public int publicVar = 10;

    public void show() {
        System.out.println("Inside Test class:");
        System.out.println("defaultVar = " + defaultVar);
        System.out.println("privateVar = " + privateVar);
        System.out.println("protectedVar = " + protectedVar);
        System.out.println("publicVar = " + publicVar);
    }
}
