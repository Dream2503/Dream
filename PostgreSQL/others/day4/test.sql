SELECT LOWER(ename)
FROM emp;

SELECT LPAD(ename, 10, '*')
FROM emp;

SELECT TRIM('N' FROM 'NIHAR')
FROM emp;

SELECT TRIM('R' FROM 'NIHAR')
FROM emp;

SELECT TRIM(TRAILING 'N' FROM ename)
FROM emp;

SELECT REPLACE(ename, 'A', 'a')
FROM emp;

SELECT ROUND(45.923, 2), ROUND(45.923, 0), ROUND(45.923, -1)
FROM emp;

SELECT empno, TO_CHAR(hiredate, 'DD-MM-YY') AS month
FROM emp;

SELECT ename, TO_CHAR(hiredate, 'fmDD Month YYYY') AS hiredate
FROM emp;

SELECT ename, COALESCE(comm, sal, 10) comm
FROM emp
ORDER BY comm;

SELECT ename,
       job,
       sal,
       CASE job
           WHEN 'PROG' THEN 1.10 * sal
           WHEN 'CLERK' THEN 1.15 * sal
           WHEN 'REP' THEN 1.2 * sal
           ELSE sal END "Revised Salary"
FROM emp;

