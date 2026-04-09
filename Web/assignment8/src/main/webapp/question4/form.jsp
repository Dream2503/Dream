<!-- Q4. Design a BMR calculator with the fields Age, Gender, Height (CM), and Weight (KG). Use the following formula to calculate and display the BMR
         (Calories/day).
         o 	For men: BMR=(10xWeight)+(6.25xHeight)–(5xAge)+5
         o 	For women: BMR=(10xWeight)+(6.25xHeight)–(5xAge)-161
-->

<html>
<body>
<h2>BMR Calculator</h2>
<form action="result.jsp">
    Age: <input type="text" name="age"><br><br>

    Gender:
    <input type="radio" name="gender" value="male"> Male
    <input type="radio" name="gender" value="female"> Female <br><br>

    Height (cm): <input type="text" name="height"><br><br>
    Weight (kg): <input type="text" name="weight"><br><br>
    <input type="submit" value="Calculate">
</form>
</body>
</html>
