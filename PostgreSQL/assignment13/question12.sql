/*
Q12. Write a PL/SQL block to calculate the perimeter of a circle for three different values of radius and simultaneously enter the values of radius
     and perimeter into a table TBL_CIRCLE.
*/

CREATE TABLE tbl_circle (
    radius    INT,
    perimeter FLOAT
);

DO $$
    DECLARE
        r INT;

    BEGIN
        FOR r IN 1..3 LOOP
            INSERT INTO tbl_circle VALUES (r, 2 * 3.14 * r);
        END LOOP;
    END;
$$;

SELECT *
FROM tbl_circle;
