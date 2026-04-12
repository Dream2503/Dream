<%@ page import="java.sql.*" %>

<%
int id = Integer.parseInt(request.getParameter("id"));

try {
	Class.forName("org.postgresql.Driver");
	String url = "jdbc:postgresql://192.168.1.17/cse_db24";
	String username = "24bcsh93";
	String password = "24bcsh93";
	Connection connection = DriverManager.getConnection(url, username, password);
	
    PreparedStatement ps = connection.prepareStatement("DELETE FROM student WHERE id=?");
    ps.setInt(1,id);
    ps.executeUpdate();

    response.sendRedirect("display_students.jsp");
} catch (Exception e){
    out.println(e);
}
%>

