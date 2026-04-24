-- Q4. Write a PL/SQL program to check whether a given number is positive, negative or zero.

\prompt 'Enter number: ' n

SELECT SET_CONFIG('my.n', :'n', FALSE);

DO $$
    DECLARE
        num INT := CURRENT_SETTING('my.n')::INT;

    BEGIN
        IF num > 0 THEN
            RAISE NOTICE 'Positive';
        ELSIF num < 0 THEN
            RAISE NOTICE 'Negative';
        ELSE
            RAISE NOTICE 'Zero';
        END IF;
    END;
$$;
