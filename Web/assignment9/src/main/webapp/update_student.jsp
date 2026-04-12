<%@ include file="navbar.jsp" %>
<%@ page import="java.sql.*" %>
<%@ page import="java.util.TimeZone" %>

<%
int id = Integer.parseInt(request.getParameter("id"));

try{
	Class.forName("org.postgresql.Driver");
    TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
    String url = "jdbc:postgresql://localhost:5432/database";
    String username = "dream";
    String password = "dream2503";
    Connection connection = DriverManager.getConnection(url, username, password);

    if (request.getMethod().equalsIgnoreCase("POST")) {
        String name = request.getParameter("name");
        String email = request.getParameter("email");
        String course = request.getParameter("course");
        int age = Integer.parseInt(request.getParameter("age"));
        double cgpa = Double.parseDouble(request.getParameter("cgpa"));

        PreparedStatement ps = connection.prepareStatement(
            "UPDATE student SET name = ?, email = ?, course = ?, age = ?, cgpa = ? WHERE id = ?;");
        ps.setString(1, name);
        ps.setString(2, email);
        ps.setString(3, course);
        ps.setInt(4, age);
        ps.setDouble(5, cgpa);
        ps.setInt(6, id);
        ps.executeUpdate();
        response.sendRedirect("display_students.jsp");
    }
    PreparedStatement ps = connection.prepareStatement("SELECT * FROM student WHERE id = ?;");
    ps.setInt(1, id);
    ResultSet resultSet = ps.executeQuery();

    if (resultSet.next()) {
%>

<h2>Update Student</h2>
<form method="post">
    Name: <input type="text" name="name" value="<%= resultSet.getString("name") %>"><br><br>
    Email: <input type="text" name="email" value="<%= resultSet.getString("email") %>"><br><br>
    Course: <input type="text" name="course" value="<%= resultSet.getString("course") %>"><br><br>
    Age: <input type="number" name="age" value="<%= resultSet.getInt("age") %>"><br><br>
    CGPA: <input type="text" name="cgpa" value="<%= resultSet.getFloat("cgpa") %>"><br><br>
    <input type="submit" value="Update">
</form>

<%
    }
} catch (Exception e) {
    out.println(e);
}
%>
