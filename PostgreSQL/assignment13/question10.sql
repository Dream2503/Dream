/*
Q10. Create a table TBL_STUDENT with attributes ROLLNO, SNAME and MARKS. Insert five records by using PL/SQL block. Then, update and display the
     marks of each student basing on the following conditions:
     o if MARKS < 5, give a grace mark of 24 to the original marks obtained  o if 5 > MARKS <= 10, offer a grace of 20 to the original marks secured
     o if 10 > MARKS < 20, update the marks by adding 15 to the original marks  o otherwise, do not change the original marks.
*/

CREATE TABLE tbl_student (
    rollno INT,
    sname  VARCHAR(20),
    marks  INT
);

DO $$
    BEGIN
        INSERT INTO tbl_student
        VALUES (1, 'A', 3),
               (2, 'B', 7),
               (3, 'C', 15),
               (4, 'D', 25),
               (5, 'E', 2);

        UPDATE tbl_student
        SET marks =
                CASE
                    WHEN marks < 5 THEN marks + 24
                    WHEN marks <= 10 THEN marks + 20
                    WHEN marks < 20 THEN marks + 15
                    ELSE marks
                    END;

    END;
$$;

SELECT *
FROM tbl_student;
