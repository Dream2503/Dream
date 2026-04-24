/*
Q15. Create a table TBL_STUD with attributes SID, SNAME, MARK1, MARK2, MARK3 and GRADE. Enter five records into it and then calculate and display the
     grade of each student according to BPUT gradation system.
*/

CREATE TABLE tbl_stud (
    sid   INT,
    sname VARCHAR(20),
    mark1 INT,
    mark2 INT,
    mark3 INT,
    grade VARCHAR(1)
);

DO $$
    DECLARE
        rec       RECORD;
        avg_marks FLOAT;
    BEGIN
        INSERT INTO tbl_stud
        VALUES (1, 'A', 80, 70, 60, NULL),
               (2, 'B', 50, 60, 55, NULL),
               (3, 'C', 40, 45, 50, NULL),
               (4, 'D', 30, 35, 25, NULL),
               (5, 'E', 90, 85, 88, NULL);

        FOR rec IN SELECT * FROM tbl_stud LOOP
            avg_marks := (rec.mark1 + rec.mark2 + rec.mark3) / 3.0;

            UPDATE tbl_stud
            SET grade =
                    CASE
                        WHEN avg_marks >= 80 THEN 'O'
                        WHEN avg_marks >= 70 THEN 'A'
                        WHEN avg_marks >= 60 THEN 'B'
                        WHEN avg_marks >= 50 THEN 'C'
                        ELSE 'F'
                        END
            WHERE sid = rec.sid;
        END LOOP;
    END;
$$;

SELECT *
FROM tbl_stud;
