package pack1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.util.TimeZone;

public class CreateTable {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");
            TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
            String url = "jdbc:postgresql://localhost:5432/database";
            String username = "dream";
            String password = "dream2503";
            Connection connection = DriverManager.getConnection(url, username, password);
            String query = """
                    CREATE TABLE studentcs (
                        roll_no INT PRIMARY KEY,
                        name VARCHAR(50),
                        age INT,
                        department VARCHAR(30),
                        cgpa NUMERIC(4, 2)
                    );""";
            Statement statement = connection.createStatement();
            statement.executeUpdate(query);
            System.out.println("Table 'studentcs' created successfully!");
            statement.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
