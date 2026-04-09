<%@ page import="java.util.*" %>
<html>
<body>
<h2>Employee Details</h2>
ID: <%= request.getParameter("id") %><br>
Name: <%= request.getParameter("name") %><br>
Mobile: <%= request.getParameter("mobile") %><br>
Email: <%= request.getParameter("email") %><br>
Gender: <%= request.getParameter("gender") %><br>
DOB: <%= request.getParameter("dob") %><br>
Address: <%= request.getParameter("address") %><br>
Country: <%= request.getParameter("country") %><br>
Languages Known:
<%
String langs[] = request.getParameterValues("lang");

if (langs != null) {
    for(String lang : langs){
        out.println(lang + " ");
    }
}
%>
</body>
</html>
