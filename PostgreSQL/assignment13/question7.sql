-- Q7. Write a PL/SQL block to find the sum of numbers from 1 to 10.

DO $$
    DECLARE
        n INT := 10;

    BEGIN
        RAISE NOTICE 'Sum = %', (n * (n + 1) / 2);
    END;
$$;
