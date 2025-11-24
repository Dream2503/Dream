//  Q2. Insert a new row into the student table fo the database.

import java.sql.*;

class Main {
    public static void main(String[] args) {
        String driverName = "org.postgresql.Driver";
        String url = "jdbc:postgresql://192.168.1.17:5432/sample_db";
        String username = "cse";
        String password = "cse123";

        try {
            Class.forName(driverName);
            Connection connection = DriverManager.getConnection(url, username, password);

            if (connection != null) {
                System.out.println("Connected");
                String query = "INSERT INTO students(first_name, last_name, mobile,email, cgpa) VALUES('A', 'B', 1234567890, 'a@mail.com', 8.6)";
                Statement statement = connection.createStatement();
                int n = statement.executeUpdate(query);

                if (n > 0) {
                    System.out.println(n + " rows inserted");
                }
            } else {
                System.out.println("Not Connected");
            }
        } catch (ClassNotFoundException ce) {
            ce.printStackTrace();
        } catch (SQLException se) {
            se.printStackTrace();
        }
    }
}
