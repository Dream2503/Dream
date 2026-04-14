-- Q1. Create a view as from Employee table having the following attributes: Ename, bdate, address, sex.
CREATE VIEW view1 AS
SELECT ename, bdate, address, sex
FROM employee;

SELECT *
FROM view1;

-- Q2. Create a view from Employee table having following attributes ename, esrno, salary, mgrsrno, dno. Names should be in sorted order.
CREATE VIEW view2 AS
SELECT ename, esrno, salary, mgrsrno, dno
FROM employee
ORDER BY ename;

SELECT *
FROM view2;

/*
Q3. Create a view from Employee table having following attributes Ename as Name, bdate as DOB, esrno, salary, mgrsrno, dno Only dept 1 & 3 employees
    should appear in the view.
*/
CREATE VIEW view3 AS
SELECT ename "name", bdate dob, esrno, salary, mgrsrno, dno
FROM employee
WHERE dno IN (1, 3);

SELECT *
FROM view3;

-- Q4. Create a view from Employee table having following attributes: esrno as eid, dno, salary as sal, comm. (45% of salary). 
CREATE VIEW view4 AS
SELECT esrno eid, salary sal, (0.45 * salary) comm
FROM employee;

SELECT *
FROM view4;

/*
Q5. Create a view from Employee table having following attributes: ename (initial capital letter), yob (year of dbate), sex as gender ,address as
    addr.
*/
CREATE VIEW view5 AS
SELECT INITCAP(ename) ename, EXTRACT(YEAR FROM bdate) yob, sex gender, address addr
FROM employee;

SELECT *
FROM view5;

-- Q6. Create a view from dept_location table having following attributes: Dnumber as dnum,dlocation as dloc( all capital letter). 
CREATE VIEW view6 AS
SELECT dnumber dnum, UPPER(dlocation) dloc
FROM dept_locations;

SELECT *
FROM view6;

-- Q7. Create a view from Employee & Department table having following attributes ename, esrno, mgrsrno, salary, dnumber, dname. 
CREATE VIEW view7 AS
SELECT ename, esrno, e.mgrsrno, salary, dnumber, dname
FROM employee e
         JOIN department d ON e.dno = d.dnumber;

SELECT *
FROM view7;

-- Q8. Create a view from Employee & dept_location having following attributes: ename, esrno, bdate, dno, dlocation.
CREATE VIEW view8 AS
SELECT ename, esrno, bdate, dno, dlocation
FROM employee e
         JOIN dept_locations dl ON e.dno = dl.dnumber;

SELECT *
FROM view8;

-- Q9. Create a view from works_on table having following attributes: esrno, time (sum of hours of an employee).
CREATE VIEW view9 AS
SELECT esrno, SUM(hours) "time"
FROM works_on
GROUP BY esrno;

SELECT *
FROM view9;

/*
Q10. Create a view from Employee, department, project, dept_location table having following attributes: esrno, ename, dno, dname , dlocation,
     pnumber, pname, plocation
*/
CREATE VIEW view10 AS
SELECT esrno, ename, dno, dname, dlocation, pnumber, pname, plocation
FROM employee e
         JOIN department d ON e.dno = d.dnumber
         JOIN project p ON p.dnum = d.dnumber
         JOIN dept_locations dl ON dl.dnumber = d.dnumber;

SELECT *
FROM view10;

/*
Q11. Create a view from Employee table  having following attributes: ename, esrno,salary as esal,mgrsrno,mgrname (manager’s name),msal (manager’s
     salry).
*/
CREATE VIEW view11 AS
SELECT e.ename, e.esrno, e.salary esal, e.mgrsrno, m.ename mgrname, m.salary msal
FROM employee e
         JOIN employee m ON e.mgrsrno = m.esrno;

SELECT *
FROM view11;
