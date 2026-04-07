// Q3. Write a JDBC program to insert two student records into the student table with values given inside the program (hard-coded).

package assignment7;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.TimeZone;

class Main {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");
            TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
            String url = "jdbc:postgresql://localhost:5432/database";
            String username = "dream";
            String password = "dream2503";
            Connection connection = DriverManager.getConnection(url, username, password);

            String query = "INSERT INTO student VALUES (?, ?, ?, ?, ?);";
            PreparedStatement ps = connection.prepareStatement(query);

            ps.setInt(1, 101);
            ps.setString(2, "Rahul");
            ps.setInt(3, 20);
            ps.setString(4, "CSE");
            ps.setDouble(5, 8.5);
            ps.executeUpdate();

            ps.setInt(1, 102);
            ps.setString(2, "Anita");
            ps.setInt(3, 21);
            ps.setString(4, "ECE");
            ps.setDouble(5, 9.1);
            ps.executeUpdate();

            System.out.println("Two student records inserted successfully!");
            ps.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
