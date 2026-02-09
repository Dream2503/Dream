-- Q1. Replace All 'A's from 'MALAYALAM' by E.
SELECT REPLACE('MALAYALAM', 'A', 'E');

-- Q2. Display 0 for all employees whose commission is NULL.
SELECT ename, COALESCE(comm, 0) comm
FROM emp;

-- Q3. Find total number of clerks.
SELECT COUNT(*) no_of_clerk
FROM emp
WHERE job = 'CLERK';

-- Q4. Find the no. of employees working under different department.
SELECT deptno, COUNT(*) no_of_emps
FROM emp
GROUP BY deptno;

-- Q5. Find total number of clerks joined after '01-jan-81'.
SELECT COUNT(*) no_of_clerk
FROM emp
WHERE job = 'CLERK'
  AND hiredate > TO_DATE('01-JAN-81', 'DD-MON-YY');

-- Q6. Find total of basis salary and commission.
SELECT (sal + COALESCE(comm, 0)) total
FROM emp;

-- Q7. Find the yearly compensation paid to all managers (12 * (sal + NVL (comm, 0)))
SELECT (12 * sal + COALESCE(comm, 0)) yearly_compensation
FROM emp
WHERE job = 'MANAGER';

-- Q8. Find the average salary of all salesmen.
SELECT AVG(sal) avg_sal_of_salesman
FROM emp
WHERE job = 'SALESMAN';

-- Q9. Who is paid most in the company?
SELECT ename, sal most_paid
FROM emp
WHERE sal = (SELECT MAX(sal) FROM emp);

-- Q10. Display the name of the highest paid employees of each department
SELECT deptno, ename, sal
FROM emp e
WHERE sal = (SELECT MAX(sal) FROM emp WHERE deptno = e.deptno);

-- Q11. Who comes first in the alphabetical order (MIN)?
SELECT MIN(ename) first
FROM emp;

-- Q12. Find the minimum salary of various categories of employees.
SELECT job, MIN(sal) min_sal
FROM emp
GROUP BY job;

-- Q13. Find the maximum salary of the employees in various depts, job wise.
SELECT job, deptno, MAX(sal) max_sal
FROM emp
GROUP BY job, deptno;

-- Q14. List the various categories of employees, depts. So that the maximum salary is greater then 1500(group by job, dept).
SELECT job, deptno, MAX(sal) max_sal
FROM emp
GROUP BY job, deptno
HAVING MAX(sal) > 1500;

-- Q15. Find the minimum and maximum salary of all managers in all depts.
SELECT deptno, MIN(sal) min_sal, MAX(sal) max_sal
FROM emp
WHERE job = 'MANAGER'
GROUP BY deptno;

-- Q16. Find the minimum salary of all managers in all depts. Where minimum salary is above 2500.
SELECT deptno, MIN(sal) min_sal
FROM emp
WHERE job = 'MANAGER'
GROUP BY deptno
HAVING MIN(sal) > 2500;
