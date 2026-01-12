-- Q1. Query the employee table.
SELECT *
FROM emp;

-- Q2. List employee number and the name of the employee.
SELECT empno, ename
FROM emp;

-- Q3. List employee number and name of employee with the headings as NUMBER and NAME.
SELECT empno AS NUMBER, ename AS NAME
FROM emp;

-- Q4. List the employees working in department 20.
SELECT *
FROM emp
WHERE deptno = 20;

-- Q5. List the employees of department 10 and 20.
SELECT *
FROM emp
WHERE deptno IN (10, 20);

-- Q6. List the employees who joined after 01/01/82.
SELECT *
FROM emp
WHERE hiredate > TO_DATE('1-JAN-1982', 'DD-MON-YYYY');

-- Q7. List the employees of dept 10 who joined after 01/01/82.
SELECT *
FROM emp
WHERE deptno = 10
  AND hiredate > TO_DATE('1-JAN-1982', 'DD-MON-YYYY');

-- Q8. List the salary of all the employees.
SELECT sal
FROM emp;

-- Q9. List the employees who do not receive commission
SELECT *
FROM emp
WHERE comm IS NULL;

-- Q10. List the employees who receive 0 commission.
SELECT *
FROM emp
WHERE comm = 0;

-- Q11. Select the employees in department 30.
SELECT *
FROM emp
WHERE deptno = 30;

-- Q12. List the names, numbers and the names of employees of all departments with department number greater than or equal to 20.
SELECT ename, empno, ename
FROM emp
WHERE deptno >= 20;

-- Q13. Find the employees whose commission is greater than 60 percent of their salary.
SELECT *
FROM emp
WHERE comm > 0.6 * sal;

-- Q14. List the name, job and salary of all employees in department 20 who earn more thanRs. 2000.
SELECT ename, job, sal
FROM emp
WHERE deptno = 20
  AND sal > 2000;

-- Q15. Find all salesmen in department 30 whose salary is greater than or equal to Rs. 1500.
SELECT *
FROM emp
WHERE job = 'SALESMAN'
  AND deptno = 30
  AND sal >= 1500;

-- Q16. Find all employees whose job is either manager or president.
SELECT *
FROM emp
WHERE job IN ('MANAGER', 'PRESIDENT');

-- Q17. Find the details of managers and clerks in department 10.
SELECT *
FROM emp
WHERE job IN ('MANAGER', 'CLERK')
  AND deptno = 10;

-- Q18. Find details of all managers in any department and all clerks in department 10.
SELECT *
FROM emp
WHERE job = 'MANAGER'
   OR job = 'CLERK' AND deptno = 10;

-- Q19. Find details of all managers in department 10 and all clerks in department 20.
SELECT *
FROM emp
WHERE job = 'MANAGER' AND deptno = 10
   OR job = 'CLERK' AND deptno = 20;

/*
Q20. Find the details of all the managers in department 10 all clerks in department 20 and all employees who are neither managers nor clerk and whose
     salary is greater than or equal to Rs. 2000.
*/
SELECT *
FROM emp
WHERE job = 'MANAGER' AND deptno = 10
   OR job = 'CLERK' AND deptno = 20
   OR job NOT IN ('MANAGER', 'CLERK') AND sal >= 2000;

-- Q21. List salaries of all employees in descending order.
SELECT *
FROM emp
ORDER BY sal DESC;
