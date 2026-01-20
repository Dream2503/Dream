SELECT *
FROM dept;

SELECT deptno, dname
FROM dept;

SELECT DISTINCT deptno
FROM dept;

SELECT ename
FROM emp
WHERE sal IN (2000, 3000, 4000);

SELECT ename, job
FROM emp
WHERE comm IS NOT NULL;

SELECT ename
FROM emp
ORDER BY ename;
