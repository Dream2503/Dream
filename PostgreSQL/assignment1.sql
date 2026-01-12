SELECT *
FROM emp;

SELECT empno, ename
FROM emp;

SELECT empno AS NUMBER, ename AS NAME
FROM emp;

SELECT *
FROM emp
WHERE deptno = 20;

SELECT *
FROM emp
WHERE deptno IN (10, 20);

SELECT *
FROM emp
WHERE hiredate > TO_DATE('1-JAN-1982', 'DD-MON-YYYY');

SELECT *
FROM emp
WHERE deptno = 10
  AND hiredate > TO_DATE('1-JAN-1982', 'DD-MON-YYYY');

SELECT sal
FROM emp;

SELECT *
FROM emp
WHERE comm IS NULL;

SELECT *
FROM emp
WHERE comm = 0;

SELECT *
FROM emp
WHERE deptno = 30;

SELECT ename, empno, ename
FROM emp
WHERE deptno >= 20;

SELECT *
FROM emp
WHERE comm > 0.6 * sal;

SELECT ename, job, sal
FROM emp
WHERE deptno = 20
  AND sal > 2000;

SELECT *
FROM emp
WHERE job = 'SALESMAN'
  AND deptno = 30
  AND sal >= 1500;

SELECT *
FROM emp
WHERE job IN ('MANAGER', 'PRESIDENT');

SELECT *
FROM emp
WHERE job IN ('MANAGER', 'CLERK')
  AND deptno = 10;

SELECT *
FROM emp
WHERE job = 'MANAGER'
   OR job = 'CLERK' AND deptno = 10;

SELECT *
FROM emp
WHERE job = 'MANAGER' AND deptno = 10
   OR job = 'CLERK' AND deptno = 20;

SELECT *
FROM emp
WHERE job = 'MANAGER' AND deptno = 10
   OR job = 'CLERK' AND deptno = 20
   OR job NOT IN ('MANAGER', 'CLERK') AND sal >= 2000;

SELECT *
FROM emp
ORDER BY sal DESC;
