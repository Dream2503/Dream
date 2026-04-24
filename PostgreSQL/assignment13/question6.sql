-- 6. Write a PL/SQL block to print even numbers from 1 to 10.

DO $$
    DECLARE
        i INT := 2;

    BEGIN
        WHILE i <= 10 LOOP
            RAISE NOTICE '%', i;
            i := i + 2;
        END LOOP;
    END;
$$;
