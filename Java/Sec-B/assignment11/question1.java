//  Q1. Display the contents of the student table from the database.

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
                String query = "SELECT * FROM students";
                Statement statement = connection.createStatement();
                ResultSet resultSet = statement.executeQuery(query);

                while (resultSet.next()) {
                    System.out.println(resultSet.getString("first_name") + "\t" + resultSet.getString("last_name") + "\t" + resultSet.getLong(
                            "mobile") + "\t" + resultSet.getString("email") + "\t" + resultSet.getDouble("cgpa"));
                }
            } else {
                System.out.println("Not Connected");
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
