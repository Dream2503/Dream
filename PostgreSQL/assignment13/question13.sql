/*
Q13. Write a PL/SQL block to assign ENAME, EMPNO, SAL and JOB from EMP table for ‘SMITH’ into some variables and display the contents of those
     variables. Mention an exception handler if no such employees exists in the table.
*/

DO $$
    DECLARE
        v_ename TEXT;
        v_empno INT;
        v_sal   INT;
        v_job   TEXT;

    BEGIN
        SELECT ename, empno, sal, job
        INTO v_ename, v_empno, v_sal, v_job
        FROM emp
        WHERE ename = 'SMITH';

        RAISE NOTICE '% % % %', v_ename, v_empno, v_sal, v_job;

    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            RAISE NOTICE 'No such employee';
    END;
$$;
