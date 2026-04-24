-- Q5. Write a PL/SQL program to check whether a given character is letter or digit.

\prompt 'Enter character: ' ch

SELECT SET_CONFIG('my.ch', :'ch', FALSE);

DO $$
    DECLARE
        c VARCHAR(1) := CURRENT_SETTING('my.ch');

    BEGIN
        IF c ~ '^[0-9]$' THEN
            RAISE NOTICE 'Digit';
        ELSE
            RAISE NOTICE 'Letter';
        END IF;
    END;
$$;
