SELECT AVG(sal), COUNT(sal), MAX(sal), MIN(sal), STDDEV(sal), SUM(sal), VARIANCE(sal)
FROM emp;

SELECT AVG(sal), MAX(sal), MIN(sal), SUM(sal)
FROM emp
WHERE job LIKE '%NA%';

SELECT MIN(hiredate), MAX(hiredate)
FROM emp;

SELECT COUNT(*)
FROM emp
WHERE deptno = 20;

SELECT COUNT(job)
FROM emp
WHERE deptno = 20;

SELECT COUNT(DISTINCT job)
FROM emp
WHERE deptno = 20;

SELECT AVG(comm)
FROM emp;

SELECT AVG(COALESCE(comm, 0))
FROM emp;

SELECT deptno, AVG(sal)
FROM emp
GROUP BY deptno;

SELECT deptno, MAX(sal)
FROM emp
GROUP BY deptno
HAVING MAX(sal) > 2500;

SELECT *
FROM emp
WHERE sal > (SELECT AVG(sal) FROM emp);
