<%
String email = request.getParameter("email");
String password = request.getParameter("password");

if (email.equals("admin@gmail.com") && password.equals("admin")) {
    request.getRequestDispatcher("welcome.jsp").forward(request, response);
} else {
    out.println("<h3>Invalid Credentials</h3>");
}
%>
