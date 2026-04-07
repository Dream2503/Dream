/* Q4. Write a JDBC program to insert a student record into the student table. Take inputs for roll_no,  name, age, department, and cgpa from the key
       board using Scanner.
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
            String query = "INSERT INTO student (roll_no, name, age, department, cgpa) VALUES (?, ?, ?, ?, ?)";

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
