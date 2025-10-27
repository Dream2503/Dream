package dream;

public class Test1 {
    public int i;
    int j;
    protected int k;

    // Constructor
    public Test1(int i, int j, int k) {
        this.i = i;
        this.j = j;
        this.k = k;
    }

    // Method
    void show() {
        System.out.println("i = " + i + ", j = " + j + ", k = " + k);
    }
}
