-- Q1. Display all the employee’s information whose job is Clerk.
SELECT *
FROM emp
WHERE job = 'CLERK';

-- Q2. Display all the employee’s information whose employee number is 7788.
SELECT *
FROM emp
WHERE empno = 7788;

-- Q3. Display all the employee’s information whose commission is greater than his salary.
SELECT *
FROM emp
WHERE comm > sal;

-- Q4. Display all the employee’s information those who are drawing a salary between 1000 and 2700.
SELECT *
FROM emp
WHERE sal BETWEEN 1000 AND 2700;

-- Q5. Display all the employee’s information whose employee number falls within a certain list.
SELECT *
FROM emp
WHERE empno IN (7521, 7839, 7934);

-- Q6. Display all the employee’s information those whose commission is not known.
SELECT *
FROM emp
WHERE comm IS NULL;

-- Q7. Display all the employee’s information whose employee name starts with an alphabet 'S'.
SELECT *
FROM emp
WHERE ename LIKE 'S%';

-- Q8. Display all the employee’s information whose employee name's third alphabet is 'O'.
SELECT *
FROM emp
WHERE ename LIKE '__O%';

-- Q9. Display all the employee’s information whose employee name is of four characters only.
SELECT *
FROM emp
WHERE ename LIKE '____';

-- Q10. Display all the employee’s information whose job is like "MANAGER".
SELECT *
FROM emp
WHERE job = 'MANAGER';

-- Q11 From Q.No. 4 to Q.No. 10, write the queries using in negative sense
SELECT *
FROM emp
WHERE sal NOT BETWEEN 1000 AND 2700;

SELECT *
FROM emp
WHERE empno NOT IN (7521, 7839, 7934);

SELECT *
FROM emp
WHERE comm IS NOT NULL;

SELECT *
FROM emp
WHERE ename NOT LIKE 'S%';

SELECT *
FROM emp
WHERE ename NOT LIKE '__O%';

SELECT *
FROM emp
WHERE ename NOT LIKE '____';

SELECT *
FROM emp
WHERE job != 'MANAGER';

-- Q12. Display the sum of salary and commission for each employee.
SELECT ename, (sal + COALESCE(comm, 0)) total_salary
FROM emp;

/* Q13. Display the sum of salary and commission for each employee by replacing commission with 100 for employees whose commission is not known or
        commission is 0.
*/
SELECT ename,
       (sal + CASE
                  WHEN comm IS NULL OR comm = 0 THEN 100
                  ELSE comm
           END) total_salary
FROM emp;

-- Q14. Display each employee's name, annual remuneration by giving a suitable alias for annual remuneration.
SELECT ename, (sal + COALESCE(comm, 0)) * 12 annual_remuneration
FROM emp;

-- Q15. Display all the employee’s information whose salary is greater than 2000 and job is according to your choice.
SELECT *
FROM emp
WHERE sal > 2000
  AND job = 'MANAGER';

-- Q16. Display all the employee’s information whose salary is greater than 3000 or job is according to your choice.
SELECT *
FROM emp
WHERE sal > 3000
   OR job = 'SALESMAN';

-- Q17. Display all the employees who are working under department 20 and not drawing a salary greater than 2000.
SELECT *
FROM emp
WHERE deptno = 20
  AND sal <= 2000;

-- Q18. Display all the employees who are drawing a salary greater than 2000 and whose job is either manager or job of your choice.
SELECT *
FROM emp
WHERE sal > 2000
  AND job IN ('MANAGER', 'SALESMAN');

-- Q19. Display the names like WARD, FORD from EMP table using pattern matching.
SELECT ename
FROM emp
WHERE ename SIMILAR TO '%(WARD|FORD)%';

/* Q20. Write a query using a pattern matching to display the names like SMITH_CLERK, ADAMS_CLERK from EMP table.
        HINT: USE CONCATENATION and LIKE Operator.
*/
SELECT (ename || '_' || job) emp_job
FROM emp
WHERE job = 'CLERK';

/* Q21. Write a query using a pattern matching to display the names like %ALLEN_SALESMAN, %ADAMS_CLERK from EMP table.
        HINT: USE CONCATENATION and LIKE Operator
*/

SELECT ename || '_' || job AS emp_job
FROM emp
WHERE ename || '_' || JOB SIMILAR TO '%(ALLEN_SALESMAN|ADAMS_CLERK)';
