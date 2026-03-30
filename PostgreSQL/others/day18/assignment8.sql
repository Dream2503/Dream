-- Q1. Display employee name, address, department no and department name.
SELECT ename, address, dnumber, dname
FROM employee e
         NATURAL JOIN department d;

-- Q2. Display managers name, department name, date of joining of manager, and salary of managers.
SELECT ename, dname, mgrstartd, salary
FROM employee
         NATURAL JOIN department;

-- Q3. Display department name, department number, and department location.
SELECT dname, dnumber, dlocation
FROM department
         NATURAL JOIN dept_locations;

-- Q4. Display project name, project number and project location and total hours of all active projects.
SELECT pname, pnumber, plocation, SUM(hours)
FROM project
         NATURAL JOIN works_on
GROUP BY pname, pnumber, plocation;

-- Q5. Display all the employees who are working in ACADEMIC.
SELECT *
FROM employee
         NATURAL JOIN department
WHERE dname = 'ACADEMIC';

-- Q6. Display the managers' details who started on '17-JUL-99'.
SELECT *
FROM employee
         NATURAL JOIN department
WHERE mgrstartd = '1999-07-17';

-- Q7. Display the employees those are working in BIO INFORMATICS.
SELECT *
FROM employee
         NATURAL JOIN project
WHERE pname = 'BIO INFORMATICS';

-- Q8. Display the details of LINUX project employees.
SELECT *
FROM employee
         NATURAL JOIN project
WHERE pname = 'LINUX';

-- Q9. Display SATYAS' project location.
SELECT *
FROM employee
         NATURAL JOIN project
WHERE ename = 'SATYA';

-- Q10. Display the details of the people who projects are located at SOUTH AFRICA.
SELECT *
FROM employee
         NATURAL JOIN project
WHERE plocation = 'SOUTH AFRICA';

-- Q11. Find the Total number of hours spend to NETWORKING.
SELECT SUM(hours) total_hours
FROM project
         NATURAL JOIN works_on
WHERE pname = 'NETWORKING';

-- Q12. Display the employees who are staying in INDIA.
SELECT *
FROM employee
         NATURAL JOIN project
WHERE plocation = 'INDIA';

-- Q13. Display all the employees total number of hours spent in their respective project.
SELECT ename, SUM(hours)
FROM employee
         NATURAL JOIN works_on
GROUP BY ename;

-- Q14. Display the total hours spent on LINUX.
SELECT SUM(hours) total_hours
FROM project
         NATURAL JOIN works_on
WHERE pname = 'LINUX';

-- Q15. Display all INDIA project members.
SELECT *
FROM employee
         NATURAL JOIN project
WHERE plocation = 'INDIA';

-- Q16.	Display the employee no, name, department no, department name, project name and no of working hours.
SELECT esrno, ename, dnumber, dname, pname, hours
FROM employee
         NATURAL JOIN department
         NATURAL JOIN project
         NATURAL JOIN works_on;
