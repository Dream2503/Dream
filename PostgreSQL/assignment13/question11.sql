/*
Q11. Write a PL/SQL block to insert numbers from 1 to 10 into a table called TBL_NUM. The table should contain two fields - NUM and CATEGORY. Then,
     check if the number is even, insert EVEN as the category and if it is odd then, insert ODD as the category into the table
*/

CREATE TABLE tbl_num (
    num      INT,
    category VARCHAR(4)
);

DO $$
    DECLARE
        i INT := 1;

    BEGIN
        WHILE i <= 10 LOOP
            IF i % 2 = 0 THEN
                INSERT INTO tbl_num VALUES (i, 'EVEN');
            ELSE
                INSERT INTO tbl_num VALUES (i, 'ODD');
            END IF;
            i := i + 1;
        END LOOP;
    END;
$$;

SELECT *
FROM tbl_num;
