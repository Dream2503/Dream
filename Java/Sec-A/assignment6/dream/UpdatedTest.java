package dream;

public class UpdatedTest {
    public int i;
    private int x;
    protected int y;

    public UpdatedTest(int i, int x, int y) {
        this.i = i;
        this.x = x;
        this.y = y;
    }

    public void show() {
        System.out.println("i = " + i + ", x = " + x + ", y = " + y);
    }
}
