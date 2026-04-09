<!-- Q5. Write JSP code to do the following:
     o	Create header.jsp and footer.jsp files.
     o	header.jsp should contain as it etitle and navigation links.
     o	footer.jsp should contain footer content (e.g., Year, Contact info).
     o	Create three JSP pages: home.jsp, about.jsp, and contact.jsp.
     o	Homepage: must include a heading, a short paragraph, and an image with a caption.
     o	About page: must include atleast two paragraphs describing the site/ organization.
     o	Contact page: must contain a contact form with fields (Name, Email, Phone, Subject, Message ). Submitted data should be displayed on a JSP
        page.
     Use the include directive to add the same header and footer to all three pages, and apply an external CSS file to style them.
-->

<%@ include file="header.jsp" %>
<h2>Contact Form</h2>
<form action="contact.jsp">
    Name: <input type="text" name="name"><br><br>
    Email: <input type="email" name="email"><br><br>
    Phone: <input type="text" name="phone"><br><br>
    Subject: <input type="text" name="subject"><br><br>
    Message:<br>
    <textarea name="message"></textarea><br><br>
    <input type="submit" value="Submit">
</form>
<%@ include file="footer.jsp" %>
