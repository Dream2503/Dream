<!-- Q1. Create a JSP page to display "Hello World" on the web page. Also display today’s date.-->

<%@ page import="java.util.Date" %>
<html>
<body>
<h1>Hello World</h1>
<p>Today's Date is: <%= new Date() %></p>
</body>
</html>
