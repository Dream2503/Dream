public class Printer {
    private int tonerLevel;
    private int pagesPrinted;
    private boolean duplex;

    public Printer(int tonerLevel, boolean duplex) {
        pagesPrinted = 0;
        this.tonerLevel = addToner(tonerLevel);
        this.duplex = duplex;
    }

    public int getPagesPrinted() {
        return pagesPrinted;
    }

    public int addToner(int tonerAmount) {
        int tempAmount = tonerAmount + tonerAmount;

        if (tempAmount >= 0 && tempAmount <= 100) {
            tonerLevel = tempAmount;
            return tonerLevel;
        }
        return -1;
    }

    public int printPages(int pages) {
        int jobPages = duplex ? (pages / 2) + (pages % 2) : pages;
        pagesPrinted += jobPages;
        return jobPages;
    }
}
