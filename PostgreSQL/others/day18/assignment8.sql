-- Q1. Display employee name, address, department no and department name.
SELECT ename, address, dnumber, dname 
FROM employee e NATURAL JOIN department d;

-- Q2. Display managers name, department name, date of joining of manager, and salary of managers.
SELECT ename, dname, mgrstartd, salary
FROM employee NATURAL JOIN department;

-- Q3. Display department name, department number, and department location.
SELECT dname, dnumber, dlocation
FROM department NATURAL JOIN dept_locations;

-- Q4. Display project name, project number and project location and total hours of all active projects.
SELECT pname, pnumber, plocation, SUM(hours)
FROM project NATURAL JOIN works_on
GROUP BY pname, pnumber, plocation;

-- Q5. Display all the employees who are working in ACADEMIC.
SELECT *
FROM employee NATURAL JOIN department
WHERE dname = 'ACADEMIC';

-- Q6. Display the managers' details who started on '17-JUL-99'.
SELECT *
FROM employee NATURAL JOIN department
WHERE mgrstartd = '1999-07-17';

-- Q7. Display the employees those are working in BIO INFORMATICS.
SELECT *
FROM employee NATURAL JOIN project
WHERE pname = 'BIO INFORMATICS';

-- Q8. Display the details of LINUX project employees.
SELECT *
FROM employee NATURAL JOIN project
WHERE pname = 'LINUX';

-- Q9. Display SATYAS' project location.
SELECT plocation
FROM employee NATURAL JOIN project
WHERE ename = 'SATYA';

-- Q10. Display the details of the people who projects are located at SOUTH AFRICA.
SELECT *
FROM employee NATURAL JOIN project
WHERE plocation = 'SOUTH AFRICA';

-- Q11. Find the Total number of hours spend to NETWORKING.
SELECT SUM(hours) total_hours
FROM project NATURAL JOIN works_on
WHERE pname = 'NETWORKING';

-- Q12. Display the employees who are staying in INDIA.
SELECT *
FROM employee e JOIN project p ON e.dno = p.dnum
WHERE plocation = 'INDIA';

-- Q13. Display all the employees total number of hours spent in their respective project.
SELECT ename, esrno, bdate, address, sex, salary, mgrsrno, dno, SUM(hours)
FROM employee NATURAL JOIN works_on
GROUP BY ename, esrno, bdate, address, sex, salary, mgrsrno, dno;

-- Q14. Display the total hours spent on LINUX.
SELECT pname, pnumber, plocation, dnum, SUM(hours) total_hours
FROM project NATURAL JOIN works_on
GROUP BY pname, pnumber, plocation, dnum
HAVING pname = 'LINUX';

-- Q15. Display all INDIA project members.
SELECT *
FROM employee NATURAL JOIN project
WHERE plocation = 'INDIA';

-- Q16.	Display the employee no, name, department no, department name, project name and no of working hours.
SELECT esrno, ename, dnumber, dname, pname, hours
FROM employee NATURAL JOIN department NATURAL JOIN project NATURAL JOIN works_on;

-- Q17. Display all the names who are belonging to the RESEARCH department.
SELECT ename
FROM employee NATURAL JOIN department
WHERE dname = 'RESEARCH';

-- Q18.	Display the details of employees who are working >5 hours.
SELECT ename, esrno, bdate, address, sex, salary, mgrsrno, dno, SUM(hours) total_hours
FROM employee NATURAL JOIN works_on
GROUP BY ename, esrno, bdate, address, sex, salary, mgrsrno, dno
HAVING SUM(hours) > 5;

-- Q19.	Who all are not in ACADEMIC department?
SELECT *
FROM employee NATURAL JOIN department
WHERE dname != 'ACADEMIC';

-- Q20.	Find the total working hours of all female employees
SELECT ename, esrno, bdate, address, sex, salary, mgrsrno, dno, SUM(hours) total_hours
FROM employee NATURAL JOIN works_on
GROUP BY ename, esrno, bdate, address, sex, salary, mgrsrno, dno
HAVING sex = 'F';

-- Q21. Find the total working hours of each manager.
SELECT ename, bdate, address, sex, salary, mgrsrno, dno, SUM(hours) total_hours
FROM employee e NATURAL JOIN department d JOIN works_on w ON d.mgrsrno = w.esrno
GROUP BY ename, bdate, address, sex, salary, mgrsrno, dno;

-- Q22.	Display the details of MEENAKSHI from all tables
SELECT ename, esrno, bdate, address ,sex, salary, mgrsrno, dname, dnumber, mgrstartd, pname, pnumber, plocation, SUM(hours) total_hours
FROM employee NATURAL JOIN department NATURAL JOIN dept_locations NATURAL JOIN project NATURAL JOIN works_on
GROUP BY ename, esrno, bdate, address, sex, salary, mgrsrno, dname, dnumber, mgrstartd, pname, pnumber, plocation
HAVING ename = 'MEENAKSHI';

-- Q23.	Display the employee names those who are in project number 19.
SELECT ename
FROM employee NATURAL JOIN project
WHERE pnumber = 19;

-- Q24. Display BOSTON employees working hours.
SELECT SUM(hours)
FROM employee NATURAL JOIN works_on
WHERE address LIKE '%BOSTON';

-- Q25.	Display project name, project location, employee serial no and total working hours of the employees
SELECT pname, plocation, esrno, SUM(hours) total_hours
FROM employee NATURAL JOIN project NATURAL JOIN works_on
GROUP BY pname, plocation, esrno;

-- Q26.	Display the total hours spends on each project.
SELECT pname, SUM(hours)
FROM project NATURAL JOIN works_on
GROUP BY pname;

-- Q27. Display the department name who is spends the Maximum hours in its project.
SELECT dname
FROM department NATURAL JOIN project NATURAL JOIN works_on
GROUP BY dname
ORDER BY SUM(hours) DESC
LIMIT 1;

-- Q28. Show the details of Ajit Nayak from employee and works_on.
SELECT *
FROM employee NATURAL JOIN works_on
WHERE ename = 'AJIT NAYAK';

-- Q29. Find the details of all employees from all tables
SELECT ename, esrno, bdate, address ,sex, salary, mgrsrno, dname, dnumber, mgrstartd, pname, pnumber, plocation, SUM(hours) total_hours
FROM employee NATURAL JOIN department NATURAL JOIN dept_locations NATURAL JOIN project NATURAL JOIN works_on
GROUP BY ename, esrno, bdate, address, sex, salary, mgrsrno, dname, dnumber, mgrstartd, pname, pnumber, plocation;

/*
TRUNCATE TABLE works_on;

INSERT INTO works_on
VALUES (495823, 11, 5.27),
       (215152, 17, 2.32),
       (495823, 11, 4.15),
       (315152, 19, 1.25),
       (334548, 19, 3.28),
       (215485, 17, 1.25),
       (295485, 17, 5.35),
       (334548, 19, 2.54),
       (295485, 17, 7.2),
       (216852, 17, 2.41),
       (334524, 19, 3.24),
       (295485, 17, 1.36),
       (495823, 11, 2.36),
       (215152, 17, 1.25),
       (495823, 11, 3.14),
       (315152, 19, 2.05),
       (334548, 19, 2.5);
*/
