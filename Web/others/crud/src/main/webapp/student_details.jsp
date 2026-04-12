<%@ include file="navbar.jsp" %>
<%@ page import="java.sql.*" %>

<%
int id = Integer.parseInt(request.getParameter("id"));

try {
	Class.forName("org.postgresql.Driver");
	String url = "jdbc:postgresql://192.168.1.17/cse_db24";
	String username = "24bcsh93";
	String password = "24bcsh93";
	Connection connection = DriverManager.getConnection(url, username, password);
	
    PreparedStatement ps = connection.prepareStatement("SELECT * FROM student WHERE id=?");
    ps.setInt(1,id);

    ResultSet resultSet = ps.executeQuery();

    if(resultSet.next()){
%>

<h2>Student Details</h2>

ID: <%= resultSet.getInt("id") %><br>
Name: <%= resultSet.getString("name") %><br>
Email: <%= resultSet.getString("email") %><br>
Course: <%= resultSet.getString("course") %><br>
Age: <%= resultSet.getInt("age") %><br>
CGPA: <%= resultSet.getDouble("cgpa") %><br>

<%
    }
} catch (Exception e) {
    out.println(e);
}
%>
