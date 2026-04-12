<%@ page import="java.sql.*" %>
<%@ page import="java.util.TimeZone" %>

<%
int id = Integer.parseInt(request.getParameter("id"));

try {
	Class.forName("org.postgresql.Driver");
    TimeZone.setDefault(TimeZone.getTimeZone("Asia/Kolkata"));
    String url = "jdbc:postgresql://localhost:5432/database";
    String username = "dream";
    String password = "dream2503";
    Connection connection = DriverManager.getConnection(url, username, password);
   
    PreparedStatement ps = connection.prepareStatement("DELETE FROM student WHERE id = ?;");
    ps.setInt(1, id);
    ps.executeUpdate();
    response.sendRedirect("display_students.jsp");
} catch (Exception e) {
    out.println(e);
}
%>
