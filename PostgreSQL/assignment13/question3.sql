-- Q3. Write a PL/SQL block to accept the value of A, B and C and display which is greater.

\prompt 'Enter A: ' a
\prompt 'Enter B: ' b
\prompt 'Enter C: ' c

SELECT SET_CONFIG('my.a', :'a', FALSE);
SELECT SET_CONFIG('my.b', :'b', FALSE);
SELECT SET_CONFIG('my.c', :'c', FALSE);

DO $$
    DECLARE
        x INT := CURRENT_SETTING('my.a')::INT;
        y INT := CURRENT_SETTING('my.b')::INT;
        z INT := CURRENT_SETTING('my.c')::INT;

    BEGIN
        IF x > y AND x > z THEN
            RAISE NOTICE 'A is greatest';
        ELSIF y > z THEN
            RAISE NOTICE 'B is greatest';
        ELSE
            RAISE NOTICE 'C is greatest';
        END IF;
    END;
$$;
