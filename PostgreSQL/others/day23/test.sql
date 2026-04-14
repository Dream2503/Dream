DROP VIEW IF EXISTS empv10;

CREATE VIEW empv10 AS
SELECT *
FROM emp
WHERE deptno = 10;

SELECT *
FROM empv10;


DROP VIEW IF EXISTS empv10;

CREATE VIEW empv5
    ("no", name, job, manager, "date", salary, commission, department_no) AS
SELECT *
FROM emp;

SELECT *
FROM empv5;


DROP VIEW IF EXISTS dept_sum_v;

CREATE VIEW dept_sum_v
    ("name", minsal, maxsal, avgsal) AS
SELECT dname, MIN(sal), MAX(sal), ROUND(AVG(sal), 2)
FROM emp
         NATURAL JOIN dept
GROUP BY dname;

SELECT *
FROM dept_sum_v;


DROP VIEW IF EXISTS empv4;

CREATE OR REPLACE VIEW empv4 AS
SELECT *
FROM emp
WHERE deptno = 20
WITH CHECK OPTION;

SELECT *
FROM empv4;
