-- Q1. Display employee name, address, department no and department name.
SELECT ename, address, dnumber, dname
FROM employee e
         JOIN department d ON e.dno = d.dnumber;

-- Q2. Display managers name, department name, date of joining of manager, and salary of managers.
SELECT ename, dname, mgrstartd, salary
FROM employee e
         JOIN department d ON e.esrno = d.mgrsrno;

-- Q3. Display department name, department number, and department location.
SELECT dname, dnumber, dlocation
FROM department
         NATURAL JOIN dept_locations;

-- Q4. Display project name, project number and project location and total hours of all active projects.
SELECT pname, pnumber, plocation, SUM(hours)
FROM project
         NATURAL JOIN works_on
GROUP BY pnumber;

-- Q5. Display all the employees who are working in ACADEMIC.
SELECT e.*
FROM employee e
         JOIN department d ON e.dno = d.dnumber
WHERE dname = 'ACADEMIC';

-- Q6. Display the managers' details who started on '17-JUL-99'.
SELECT *
FROM employee e
         JOIN department d ON e.esrno = d.mgrsrno
WHERE mgrstartd = '1999-07-17';

-- Q7. Display the employees those are working in BIO INFORMATICS.
SELECT e.*
FROM employee e
         NATURAL JOIN project
WHERE pname = 'BIO INFORMATICS';

-- Q8. Display the details of LINUX project employees.
SELECT e.*
FROM employee e
         NATURAL JOIN project
WHERE pname = 'LINUX';

-- Q9. Display SATYAS' project location.
SELECT plocation
FROM employee
         NATURAL JOIN project
WHERE ename = 'SATYA';

-- Q10. Display the details of the people who projects are located at SOUTH AFRICA.
SELECT e.*
FROM employee e
         NATURAL JOIN project
WHERE plocation = 'SOUTH AFRICA';

-- Q11. Find the Total number of hours spend to NETWORKING.
SELECT SUM(hours) total_hours
FROM project
         NATURAL JOIN works_on
WHERE pname = 'NETWORKING';

-- Q12. Display the employees who are staying in INDIA.
SELECT e.*
FROM employee e
         NATURAL JOIN project
WHERE plocation = 'INDIA';

-- Q13. Display all the employees total number of hours spent in their respective project.
SELECT e.*, SUM(hours) total_hours
FROM employee e
         NATURAL JOIN works_on
GROUP BY e.esrno;

-- Q14. Display the total hours spent on LINUX.
SELECT p.*, SUM(hours) total_hours
FROM project p
         NATURAL JOIN works_on
WHERE pname = 'LINUX'
GROUP BY pnumber;

-- Q15. Display all INDIA project members.
SELECT e.*
FROM employee e
         NATURAL JOIN project
WHERE plocation = 'INDIA';

-- Q16. Display the employee no, name, department no, department name, project name and no of working hours.
SELECT e.esrno, ename, dnumber, dname, pname, SUM(hours) total_hours
FROM employee e
         JOIN department d ON e.dno = d.dnumber
         JOIN project p ON d.dnumber = p.dnum
         JOIN works_on w ON e.esrno = w.esrno
GROUP BY e.esrno, dnumber, pname;

-- Q17. Display all the names who are belonging to the RESEARCH department.
SELECT ename
FROM employee e
         JOIN department d ON e.dno = d.dnumber
WHERE dname = 'RESEARCH';

-- Q18.	Display the details of employees who are working >5 hours.
SELECT e.*, SUM(hours) total_hours
FROM employee e
         NATURAL JOIN works_on
GROUP BY e.esrno
HAVING SUM(hours) > 5;

-- Q19.	Who all are not in ACADEMIC department?
SELECT *
FROM employee e
         JOIN department d ON e.dno = d.dnumber
WHERE dname != 'ACADEMIC';

-- Q20.	Find the total working hours of all female employees.
SELECT e.*, SUM(hours) total_hours
FROM employee e
         NATURAL JOIN works_on
WHERE sex = 'F'
GROUP BY e.esrno;

-- Q21. Find the total working hours of each manager.
SELECT e.*, SUM(hours) total_hours
FROM employee e
         JOIN department d ON e.esrno = d.mgrsrno
         JOIN works_on w ON e.esrno = w.esrno
GROUP BY e.esrno;

-- Q22.	Display the details of MEENAKSHI from all tables
SELECT e.*, d.*, dlocation, p.*, SUM(hours) total_hours
FROM employee e
         JOIN department d ON e.dno = d.dnumber
         JOIN dept_locations dl ON d.dnumber = dl.dnumber
         JOIN project p ON d.dnumber = p.dnum
         JOIN works_on w ON e.esrno = w.esrno
WHERE ename = 'MEENAKSHI'
GROUP BY e.esrno, d.dnumber, dlocation, pnumber;

-- Q23.	Display the employee names those who are in project number 19.
SELECT ename
FROM employee
         NATURAL JOIN project
WHERE pnumber = 19;

-- Q24. Display BOSTON employees working hours.
SELECT e.*, SUM(hours) total_hours
FROM employee e
         NATURAL JOIN works_on
WHERE address LIKE '%BOSTON'
GROUP BY e.esrno;

-- Q25. Display project name, project location, employee serial no and total working hours of the employees.
SELECT pname, plocation, e.esrno, SUM(hours) total_hours
FROM employee e
         JOIN works_on w ON e.esrno = w.esrno
         JOIN project p ON p.pnumber = w.pno
GROUP BY e.esrno, pnumber;

-- Q26. Display the total hours spends on each project.
SELECT pname, SUM(hours) total_hours
FROM project
         NATURAL JOIN works_on
GROUP BY pnumber;

-- Q27. Display the department name who is spends the Maximum hours in its project.
SELECT d.*, SUM(hours)
FROM department d
         JOIN project p ON d.dnumber = p.dnum
         JOIN works_on w ON p.pnumber = w.pno
GROUP BY dnumber
ORDER BY SUM(hours) DESC
LIMIT 1;

-- Q28. Show the details of Ajit Nayak from employee and works_on.
SELECT *
FROM employee
         NATURAL JOIN works_on
WHERE ename = 'AJIT NAYAK';

-- Q29. Find the details of all employees from all tables.
SELECT e.*, d.*, dlocation, p.*, SUM(hours) total_hours
FROM employee e
         JOIN department d ON e.dno = d.dnumber
         JOIN dept_locations dl ON d.dnumber = dl.dnumber
         FULL JOIN project p ON d.dnumber = p.dnum
         FULL JOIN works_on w ON e.esrno = w.esrno
GROUP BY e.esrno, d.dnumber, dlocation, pnumber;
