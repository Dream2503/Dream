public class Main {
    public static void main(String[] args) {
        System.out.println("New Score is " + calculateScore("Dream", 500));
        System.out.println("New Score is " + calculateScore(10));
    }

    public static int calculateScore(String playerName, int score) {
        System.out.println("Player " + playerName + " scored " + score + " points");
        return score * 1000;
    }

    public static int calculateScore(int score) {
        return calculateScore("Anonymous", score);
    }

    public static int calculateScore() {
        System.out.println("No player name, no player score.");
        return 0;
    }
}