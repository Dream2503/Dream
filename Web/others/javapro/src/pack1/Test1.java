package pack1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.util.TimeZone;

public class Test1 {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");
            TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
            String url = "jdbc:postgresql://localhost:5432/database";
            String username = "dream";
            String password = "dream2503";
            Connection connection = DriverManager.getConnection(url, username, password);

            if (connection != null) {
                System.out.println("Connected...");
                connection.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
