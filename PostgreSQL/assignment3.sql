/*
Q1. Display the names, jobs and bonus for all employees assuming all managers get a bonus of Rs. 500, clerks get Rs.200 and all others except the
    president Rs.350. The president gets 20 percent of his salary as bonus.
*/
SELECT ename,
       job,
       CASE job
           WHEN 'MANAGER' THEN 500
           WHEN 'CLERK' THEN 200
           WHEN 'PRESIDENT' THEN ROUND(0.2 * sal, 0)
           ELSE 350
           END bonus
FROM emp;

/*
Q2. Display the names of all employees and their bonus. Assume each employee gets a bonus of 20 percent of his salary subject to the maximum of Rs.
    200.
*/
SELECT ename,
       CASE
           WHEN 0.2 * sal <= 200 THEN ROUND(0.2 * sal, 0)
           ELSE 200
           END bonus
FROM emp;

-- Q3. Display the employee details in the following manner. "Miller joined on the twenty-third of January of the year eighty second".
SELECT ename,
       hiredate,
       INITCAP(ename) || ' joined on the ' || TO_CHAR(hiredate, 'DDSPth') || ' of ' || TO_CHAR(hiredate, 'FMMonth') ||
       ' of the year ' ||
       TO_CHAR(hiredate, 'YYSPth') description
FROM emp;

/*
Q4. Display the name of all employees, and "Greater" or "smaller" depending on where the salary of the employees is greater than or less than 1500.
*/
SELECT ename,
       sal,
       CASE
           WHEN sal > 1500 THEN 'Greater'
           ELSE 'Smaller'
           END type
FROM emp;

/*
Q5. Display the DA of all employees and calculation is in the following manner.
        If salary >=5000 then DA is 75% of Salary.
        If salary >=3000 and salary<5000 then DA is 60% of Salary Else DA is 50% of Salary.
*/
SELECT *,
       ROUND(CASE
                 WHEN sal >= 5000 THEN 0.75 * sal
                 WHEN sal >= 3000 THEN 0.6 * sal
                 ELSE 0.5 * sal
                 END, 0) "DA"
FROM emp;

-- Q6. Display the names, job and hire date of employees with there hire dates in desc order inside each department.
SELECT ename, job, hiredate, deptno
FROM emp
ORDER BY deptno, hiredate DESC;

-- Q7. What would be the date after two months?
SELECT ename, hiredate, (hiredate + INTERVAL '2 months') after
FROM emp;

/*
Q8. List the employee number, name of all employees Employee names should have only the first letter in upper case and department no in descending
    order.
*/
SELECT empno, INITCAP(ename), deptno
FROM emp
ORDER BY deptno DESC;

-- Q9. Concatenate the name of the person with his job separated by three spaces (CONCAT).
SELECT CONCAT(ename, '   ', job) name_job
FROM emp;

-- Q10. Display the names of all employees, padding them to the right up to 16 characters with.
SELECT RPAD(ename, 16, '.') ename
FROM emp;

-- Q11. Show the first three characters of names of all employees.
SELECT SUBSTR(ename, 1, 3) ename
FROM emp;

-- Q12. Find the salary of all employees rounding it to the nearest Rs.1000.
SELECT ename, ROUND(sal, -3) sal
FROM emp;

-- Q13. Find employees name and job whose employees names last character is equal to jobs last character.
SELECT ename, job
FROM emp
WHERE SUBSTR(ename, LENGTH(ename)) = SUBSTR(job, LENGTH(job));

-- Q14. Display the names and salary of the employees in the descending order of their income.
SELECT ename, sal
FROM emp
ORDER BY sal DESC;

-- Q15. Display the names of all employees with any "A" at any place of the name.
SELECT ename
FROM emp
WHERE ename LIKE '%A%';

-- Q16. Show all employees who were hired in the first half of the month (Before the 16th of the month).
SELECT *
FROM emp
WHERE EXTRACT(DAY FROM hiredate) < 16;

-- Q17. Show all employees, and indicate with "YES" or "NO" whether they receive a commission.
SELECT *,
       CASE
           WHEN comm IS NULL OR comm = 0 THEN 'NO'
           ELSE 'YES'
           END is_receive_commission
FROM emp;

-- Q18. Show those employees that have a name starting with J, K, L, or M.
SELECT *
FROM emp
WHERE ename SIMILAR TO '[J-M]%';

-- Q19. Display the length of all employees.
SELECT ename, LENGTH(ename) length
FROM emp;

-- Q20. Display the name and job of all employees who do not have a manager.
SELECT ename, job
FROM emp
WHERE mgr IS NULL;

-- Q21. Find all employees whose name are 5 characters long and end with "N".
SELECT *
FROM emp
WHERE LENGTH(ename) = 5
  AND ename LIKE '%N';

-- Q22. Display the employee name and department no of all employees in department 10,30 in alphabetical order by name.
SELECT ename, deptno
FROM emp
WHERE deptno IN (10, 30)
ORDER BY ename;

-- Q23. Find employees who do not receive a commission or whose commission is less than Rs.100. (comm is null or comm < 100)
SELECT *
FROM emp
WHERE comm IS NULL
   OR comm < 100;

-- Q24. Find the employees whose commission is Rs.0.
SELECT *
FROM emp
WHERE comm = 0;
