-- Q9. Write a PL/SQL block to accept a number and print it in reverse order.

\prompt 'Enter number: ' n

SELECT SET_CONFIG('my.n', :'n', FALSE);

DO $$
    DECLARE
        num INT := CURRENT_SETTING('my.n')::INT;
        rev INT := 0;

    BEGIN
        WHILE num > 0
        LOOP
            rev := rev * 10 + (num % 10);
            num := num / 10;
        END LOOP;
        RAISE NOTICE 'Reverse = %', rev;
    END;
$$;
