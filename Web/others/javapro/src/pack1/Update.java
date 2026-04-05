package pack1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.Scanner;
import java.util.TimeZone;

public class Update {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");
            TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
            String url = "jdbc:postgresql://localhost:5432/database";
            String username = "dream";
            String password = "dream2503";
            Connection connection = DriverManager.getConnection(url, username, password);
            Scanner sc = new Scanner(System.in);
            String query = "INSERT INTO studentcs (roll_no, name, age, department, cgpa) VALUES (?, ?, ?, ?, ?)";

            PreparedStatement ps = connection.prepareStatement(query);
            System.out.print("Enter your Roll no.: ");
            ps.setInt(1, sc.nextInt());
            System.out.print("Enter your Name: ");
            ps.setString(2, sc.next());
            System.out.print("Enter your Age: ");
            ps.setInt(3, sc.nextInt());
            System.out.print("Enter your Branch: ");
            ps.setString(4, sc.next());
            System.out.print("Enter your CGPA: ");
            ps.setDouble(5, sc.nextDouble());
            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("Record inserted successfully!");
            }
            ps.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

