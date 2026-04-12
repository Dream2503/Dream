<%@ include file="navbar.jsp" %>
<%@ page import="java.sql.*" %>
<%@ page import="java.util.TimeZone" %>

<h2>Student List</h2>
<table border="1">
<tr>
    <th>ID</th>
    <th>Name</th>
    <th>Email</th>
    <th>Course</th>
    <th>Age</th>
    <th>CGPA</th>
    <th>Actions</th>
</tr>

<%
try {
	Class.forName("org.postgresql.Driver");
    TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
    String url = "jdbc:postgresql://localhost:5432/database";
    String username = "dream";
    String password = "dream2503";
    Connection connection = DriverManager.getConnection(url, username, password);
    
    Statement statement = connection.createStatement();
    ResultSet resultSet = statement.executeQuery("SELECT * FROM student;");

    while (resultSet.next()) {
%>
<tr>
    <td><%= resultSet.getInt("id") %></td>
    <td><%= resultSet.getString("name") %></td>
    <td><%= resultSet.getString("email") %></td>
    <td><%= resultSet.getString("course") %></td>
    <td><%= resultSet.getInt("age") %></td>
    <td><%= resultSet.getDouble("cgpa") %></td>
    <td>
        <a href="student_details.jsp?id=<%= resultSet.getInt("id") %>">Details</a> |
        <a href="update_student.jsp?id=<%= resultSet.getInt("id") %>">Update</a> |
        <a href="delete_student.jsp?id=<%= resultSet.getInt("id") %>">Delete</a>
    </td>
</tr>
<%
    }
} catch (Exception e) {
    out.println(e);
}
%>
</table>
