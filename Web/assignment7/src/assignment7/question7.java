// Q7. Write a JDBC program to delete a student record based on roll_no. Accept the roll number from the keyboard.

package assignment7;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.Scanner;
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

            Scanner sc = new Scanner(System.in);
            String query = "DELETE FROM student WHERE roll_no = ?";
            PreparedStatement ps = connection.prepareStatement(query);
            System.out.print("Enter Roll No to delete: ");
            ps.setInt(1, sc.nextInt());
            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("Record deleted successfully!");
            } else {
                System.out.println("No student found with given roll number.");
            }
            ps.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
