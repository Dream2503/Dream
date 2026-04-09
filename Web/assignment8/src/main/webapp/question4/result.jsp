<html>
<body>
<%
int age = Integer.parseInt(request.getParameter("age"));
double height = Double.parseDouble(request.getParameter("height"));
double weight = Double.parseDouble(request.getParameter("weight"));
String gender = request.getParameter("gender");
double bmr;

if (gender.equals("male")) {
    bmr = (10 * weight) + (6.25 * height) - (5 * age) + 5;
} else {
    bmr = (10 * weight) + (6.25 * height) - (5 * age) - 161;
}
%>
<h2>Your BMR is: <%= bmr %> Calories/day</h2>
</body>
</html>
