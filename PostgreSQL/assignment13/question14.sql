/*
Q14. Accept the values of EMPNO, ENAME, SAL and COMM into some variables and then find the total salary of each employee who is a ‘CLERK’ and
     ‘SALESMAN’.
*/

DO $$
    DECLARE
        total FLOAT;

    BEGIN
        SELECT SUM(sal + COALESCE(comm, 0))
        INTO total
        FROM emp
        WHERE job IN ('CLERK', 'SALESMAN');

        RAISE NOTICE 'Total Salary = %', total;
    END;
$$;
