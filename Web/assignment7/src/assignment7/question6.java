/* Q6. Write a JDBC program to update the CGPA of a student based on their roll_no. Take the targeted student’s roll number and updated cgpa as input
       from the keyboard.
*/

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
            String query = "UPDATE student SET cgpa = ? WHERE roll_no = ?";
            PreparedStatement ps = connection.prepareStatement(query);

            System.out.print("Enter Roll No to update: ");
            ps.setInt(2, sc.nextInt());
            System.out.print("Enter new CGPA: ");
            ps.setDouble(1, sc.nextDouble());
            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("CGPA updated successfully!");
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
