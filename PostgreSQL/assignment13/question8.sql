-- Q8. Write a PL/SQL block to accept a number and find the sum of the digits of that number.

\prompt 'Enter number: ' n

SELECT SET_CONFIG('my.n', :'n', FALSE);

DO $$
    DECLARE
        num INT := CURRENT_SETTING('my.n')::INT;
        sum INT := 0;

    BEGIN
        WHILE num > 0
        LOOP
            sum := sum + (num % 10);
            num := num / 10;
        END LOOP;
        RAISE NOTICE 'Sum of digits = %', sum;
    END;
$$;
