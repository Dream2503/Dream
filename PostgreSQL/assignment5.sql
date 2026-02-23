-- Q1. List the employee's name, job, salary, and department number for those employee working in Smith's department.
SELECT ename, job, sal, deptno
FROM emp
WHERE deptno = (SELECT deptno FROM emp WHERE ename = 'SMITH');

-- Q2. Display salary of employees according to department and job those are getting salary more than average salary.
SELECT e.deptno, e.job, e.sal
FROM emp e
WHERE e.sal > (SELECT AVG(sal) FROM emp WHERE deptno = e.deptno AND job = e.job);

-- Q3. Display Deptno, Empno and name, those have department name "Research".
SELECT deptno, empno, ename
FROM emp
WHERE deptno = (SELECT deptno FROM dept WHERE dname = 'RESEARCH');

-- Q4. List Ename, job, annual Sal, and Deptno for employees, who earns more than Jones salary.
SELECT ename, job, (12 * sal) annual_salary, deptno
FROM emp
WHERE sal > (SELECT sal FROM emp WHERE ename = 'JONES');

-- Q5. Display the employees those have joined after miller .
SELECT *
FROM emp
WHERE hiredate > (SELECT hiredate FROM emp WHERE ename = 'MILLER');

-- Q6. Find the employees who earn salary equal to the minimum salary in the company.
SELECT *
FROM emp
WHERE sal = (SELECT MIN(sal) FROM emp);

-- Q7. Find all employees who have the same job as BLAKE.
SELECT *
FROM emp
WHERE job = (SELECT job FROM emp WHERE ename = 'BLAKE');

-- Q8. Find all the employees who earn more than every employee in department 30.
SELECT *
FROM emp
WHERE sal > (SELECT MAX(sal) FROM emp WHERE deptno = 30);

-- Q9. Display employees who earn more than the lowest salary in department 30.
SELECT *
FROM emp
WHERE sal > (SELECT MIN(sal) FROM emp WHERE deptno = 30);

-- Q10. Display the departments, which have an average salary more than that of department 30.
SELECT deptno, (SELECT dname FROM dept d WHERE d.deptno = e.deptno)
FROM emp e
GROUP BY deptno
HAVING AVG(sal) > (SELECT AVG(sal) FROM emp WHERE deptno = 30);

-- Q11. Display the job with the highest average salary.
SELECT job
FROM emp
GROUP BY job
HAVING AVG(sal) = (SELECT MAX(avg) FROM (SELECT AVG(sal) FROM emp GROUP BY job));

-- Q12. For each employee display the number of days passed since the employee joined in the company.
SELECT *, (CURRENT_DATE - hiredate) days_passed
FROM emp;

-- Q13. Display the employee those are working department of location Chicago in the company.
SELECT *
FROM emp
WHERE deptno = (SELECT deptno FROM dept WHERE loc = 'CHICAGO');

-- Q14. Display the name, job and hire date of employees whose salary is greater than the highest salary of sales department.
SELECT ename, job, hiredate
FROM emp
WHERE sal > (SELECT MAX(sal) FROM emp WHERE deptno = (SELECT deptno FROM dept WHERE dname = 'SALES'));

-- Q15. Find the 2nd maximum salary of employees.
SELECT MAX(sal) max2
FROM (SELECT sal FROM emp WHERE sal != (SELECT MAX(sal) FROM emp));

-- Q16. Count the department where no of employees are more than 5.
SELECT COUNT(*) count
FROM dept
WHERE deptno = (SELECT deptno FROM emp GROUP BY deptno HAVING COUNT(*) > 5);

-- Q17. Count the no of employees those are not getting any commission.
SELECT COUNT(*) count
FROM (SELECT * FROM emp WHERE comm IS NULL OR comm = 0);
