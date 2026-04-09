<!-- Q6. Design a login form with an email and password field. If the email id is given by the user as admin@gmail.com and the password as admin,
         forward the request to welcome.jsp else display “Invalid Credentials” message.
-->

<html>
<body>
<h2>Login</h2>
<form action="check.jsp">
    Email: <input type="text" name="email"><br><br>
    Password: <input type="password" name="password"><br><br>
    <input type="submit" value="Login">
</form>
</body>
</html>
