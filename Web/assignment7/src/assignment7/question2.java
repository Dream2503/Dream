/* Q2. Write a Java program to create a table named student in the connected database with the following fields: roll_no (INT, Primary Key), name
       (VARCHAR(50)), age (INT), department (VARCHAR(30)), cgpa (FLOAT(4,2)
*/

package assignment7;

import java.sql.Connection;
import java.sql.DriverManager;
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

            String query = """
                    CREATE TABLE student (
                        roll_no INT PRIMARY KEY,
                        name VARCHAR(50),
                        age INT,
                        department VARCHAR(30),
                        cgpa NUMERIC(4, 2)
                    );""";
            Statement statement = connection.createStatement();
            statement.executeUpdate(query);
            System.out.println("Table 'student' created successfully!");

            statement.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
