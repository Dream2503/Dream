<%@ include file="header.jsp" %>
<h2>Submitted Details</h2>
Name: <%= request.getParameter("name") %><br>
Email: <%= request.getParameter("email") %><br>
Phone: <%= request.getParameter("phone") %><br>
Subject: <%= request.getParameter("subject") %><br>
Message: <%= request.getParameter("message") %><br>
<%@ include file="footer.jsp" %>
