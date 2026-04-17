-- Q1. Create an index on esrno of employee table.
CREATE INDEX esrno_employee_idx
    ON employee (esrno);

-- Q2. Create an index on (esrno, pno) of works_on table.  
CREATE INDEX esrno_pno_works_on_idx
    ON works_on (esrno, pno);

-- Q3. Create an unique index on esrno of employee table.
CREATE UNIQUE INDEX unique_esrno_employee_idx
    ON employee (esrno);

-- Q4. Create a reverse index on salary of employee
CREATE INDEX reverse_salary_employee_idx
    ON employee (salary DESC);

-- Q5. Change the index in Q1 to nonreverse
CREATE INDEX nonreverse_esrno_employee_idx
    ON employee (esrno ASC);
