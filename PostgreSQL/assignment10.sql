/*
Q1. Write a query to return all distinct rows retrieved by either of the query whose department number is 10 or department number is 30. HINT: Set
    operator
*/
SELECT *
FROM emp
WHERE deptno = 10
UNION
SELECT *
FROM emp
WHERE deptno = 30;

-- Q2. Write a query to return only rows retrieved by both of the query whose department number is 10 or department number is 30. HINT: Set operator
SELECT *
FROM emp
WHERE deptno = 10
INTERSECT
SELECT *
FROM emp
WHERE deptno = 30;

/* Q3. Write a query to return all rows retrieved by first query that are not in the second query containing department number is 10 or department
       number is 30. HINT: Set operator
*/
SELECT *
FROM emp
WHERE deptno = 10
EXCEPT
SELECT *
FROM emp
WHERE deptno = 30;

-- Q4. Find out the employees who are working in department number 10 and drawing a salary more than 1000. 
SELECT *
FROM emp
WHERE deptno = 10
INTERSECT
SELECT *
FROM emp
WHERE sal > 1000;

-- Q5. Write a query to return all rows whose department number is 10 or department number is 30. Hint : Set operator 
SELECT *
FROM emp
WHERE deptno = 10
UNION
SELECT *
FROM emp
WHERE deptno = 30;

-- Q6. Write a query that returns the employee names by both query those who are working in department 30 or are working as "Salesman"
SELECT *
FROM emp
WHERE deptno = 30
UNION
SELECT *
FROM emp
WHERE job = 'SALESMAN';

-- Q7. Write a query that returns all the departments that do not contain any employees. 
SELECT *
FROM dept d
WHERE (SELECT COUNT(*)
       FROM emp e
       WHERE e.deptno = d.deptno) = 0;

-- Q8. Write a query that returns the employee names retrieved by either query those who are working under Jones or working under King. 
SELECT ename
FROM emp
WHERE mgr = (SELECT empno
             FROM emp
             WHERE ename = 'JONES')
UNION
SELECT ename
FROM emp
WHERE mgr = (SELECT empno
             FROM emp
             WHERE ename = 'KING');
