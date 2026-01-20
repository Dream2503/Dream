SELECT sal + 500
FROM emp;

SELECT *
FROM emp
WHERE sal > 3000;

SELECT *
FROM emp
WHERE deptno = 10;

SELECT *
FROM emp
WHERE job <> 'CLERK';

SELECT *
FROM emp
WHERE ename LIKE 'S%';

SELECT *
FROM emp
WHERE ename ILIKE 's%';

SELECT *
FROM emp
WHERE deptno IN (10, 20, 30);

SELECT *
FROM emp
WHERE sal BETWEEN 2000 AND 4000;

SELECT *
FROM emp
WHERE comm IS NULL;

SELECT *
FROM emp
WHERE ename SIMILAR TO '(A|S)%';

SELECT *
FROM emp
WHERE ename SIMILAR TO '%(N|R)';

SELECT *
FROM emp
WHERE ename ~ '^S';

SELECT *
FROM emp
WHERE ename ~ 'N$';

SELECT *
FROM emp
WHERE ename ~ '^.....$';

SELECT *
FROM emp
WHERE ename ~* '^(a|s)';
