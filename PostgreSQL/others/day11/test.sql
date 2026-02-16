-- Example 1
SELECT *
FROM emp
WHERE sal > (SELECT sal FROM emp WHERE ename = 'SMITH');

-- Example 2
SELECT *
FROM emp
WHERE deptno = (SELECT deptno FROM emp WHERE ename = 'SMITH');

-- Example 3
SELECT *
FROM emp
WHERE deptno = (SELECT deptno FROM dept WHERE dname = 'ACCOUNTING');

-- Question 1
SELECT *
FROM emp
WHERE mgr = (SELECT empno FROM emp WHERE ename = 'KING');

-- Question 2
SELECT *
FROM emp
WHERE deptno = (SELECT deptno FROM emp WHERE ename = 'ALLEN')
  AND sal < (SELECT sal FROM emp WHERE ename = 'BLAKE');

-- Question 3
SELECT *
FROM emp
WHERE sal = (SELECT MAX(sal) FROM emp);

-- Question 4
SELECT *
FROM emp
WHERE sal > (SELECT AVG(sal) FROM emp);

-- Question 5
SELECT deptno
FROM emp
GROUP BY deptno
HAVING AVG(sal) > (SELECT AVG(sal) FROM emp WHERE deptno = 10);

-- Question 6
SELECT AVG(sal) min_avg
FROM emp
GROUP BY deptno
HAVING AVG(sal) = (SELECT MIN(avg) FROM (SELECT AVG(sal) avg FROM emp GROUP BY deptno));

-- Question 7
SELECT *
FROM emp
WHERE deptno = (SELECT deptno FROM dept WHERE loc = 'DALLAS');

-- Question 8
SELECT *
FROM emp
WHERE deptno = 10
  AND sal = (SELECT MIN(sal) FROM emp WHERE deptno = 10);

-- Question 9
SELECT *
FROM emp
WHERE hiredate < (SELECT hiredate FROM emp WHERE ename = 'SMITH');

-- Question 11
SELECT *
FROM emp
WHERE mgr = (SELECT empno FROM emp WHERE ename = 'BLAKE');

-- Question 12
SELECT mgr
FROM emp
GROUP BY mgr
HAVING COUNT(*) = (SELECT MAX(count) FROM (SELECT COUNT(*) FROM emp GROUP BY mgr));

-- Question 13
SELECT deptno
FROM emp
GROUP BY deptno
HAVING COUNT(*) = (SELECT MAX(count) FROM (SELECT COUNT(*) FROM emp GROUP BY deptno));

-- SELECT ename,sal,deptno FROM emp WHERE deptno = (SELECT deptno FROM dept WHERE dname IN ('SALES', 'ACCOUNTING'));

SELECT *
FROM emp
WHERE deptno IN (SELECT deptno FROM dept WHERE dname IN ('SALES', 'ACCOUNTING'));

SELECT *
FROM emp
WHERE deptno != 10
  AND sal < ANY (SELECT sal FROM emp WHERE deptno = 10);

SELECT *
FROM emp
WHERE deptno != 10
  AND sal < ALL (SELECT sal FROM emp WHERE deptno = 10);

SELECT *
FROM emp
WHERE (deptno, sal) IN (SELECT deptno, MAX(sal) FROM emp GROUP BY deptno);

SELECT *
FROM emp
WHERE (mgr, sal) IN (SELECT mgr, MIN(sal) FROM emp GROUP BY mgr);

SELECT ename, deptno, (SELECT MAX(sal) FROM emp WHERE deptno = e.deptno) highest_sal
FROM emp e;

SELECT *
FROM emp e
WHERE sal > (SELECT AVG(sal) FROM emp WHERE deptno = e.deptno);

SELECT *
FROM emp e
WHERE EXISTS (SELECT '' FROM emp WHERE mgr = e.empno);

SELECT *
FROM emp
WHERE empno IN (SELECT mgr FROM emp WHERE mgr IS NOT NULL);

SELECT *
FROM dept
WHERE deptno IN (SELECT deptno FROM emp);

SELECT *
FROM dept d
WHERE EXISTS (SELECT '' FROM emp WHERE deptno = d.deptno);

-- DELETE FROM emp e WHERE sal < (SELECT AVG(sal) FROM emp WHERE deptno = e.deptno);

-- UPDATE emp e1 SET sal = (SELECT MAX(sal) FROM emp e2 WHERE e1.deptno = e2.deptno);

SELECT *
FROM emp
WHERE empno NOT IN (SELECT mgr FROM emp);

SELECT *
FROM emp
WHERE empno NOT IN (SELECT mgr FROM emp WHERE mgr IS NOT NULL);
