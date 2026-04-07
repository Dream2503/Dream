// Q5. Write a JDBC program to display all records from the student table.

package assignment7;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
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

            String query = "SELECT * FROM student";
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(query);
            System.out.println("Student Records:\n");

            while (resultSet.next()) {
                System.out.println("Roll No: " + resultSet.getInt("roll_no"));
                System.out.println("Name: " + resultSet.getString("name"));
                System.out.println("Age: " + resultSet.getInt("age"));
                System.out.println("Department: " + resultSet.getString("department"));
                System.out.println("CGPA: " + resultSet.getFloat("cgpa"));
                System.out.println("---------------------------------------------");
            }
            resultSet.close();
            statement.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
