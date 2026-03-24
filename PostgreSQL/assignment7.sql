-- employee
CREATE TABLE employee (
    ename   VARCHAR(16),
    esrno   INT PRIMARY KEY,
    bdate   DATE,
    address VARCHAR(16),
    sex     CHAR(1),
    salary  INT,
    mgrsrno INT,
    dno     INT
);

INSERT INTO employee
VALUES ('AJIT NAYAK', 133100, '25-APR-55', '73 BOSTON', 'M', 35000, NULL, 1),
       ('SATYA', 495823, '17-JUL-66', '26 FINE OAK', 'M', 32770, 133100, 4),
       ('AJIT BEHERA', 315152, '09-JUL-71', '10 KALINGA', 'M', 32802, 133100, 3),
       ('UMASHANKAR', 216852, '17-JUL-67', '26 FINE OAK', 'M', 32770, 133100, 2),
       ('BHAGWAT', 215152, '23-MAR-71', '55 FLORIDA', 'M', 32802, 216852, 2),
       ('MEENAKSHI', 334548, '25-APR-79', '73 BRIKLY', 'F', 25125, 315152, 3),
       ('JASWASI', 215485, '12-AUG-79', '17 BOSTON', 'M', 20500, 495823, 4),
       ('NIHAR NAYAK', 334524, '17-DEC-66', '73 DALLAS', 'M', 29105, 315152, 3),
       ('DEBASMITA', 295485, '16-APR-70', '1 QUEENS LAND', 'F', 20500, 216852, 2);

-- department
CREATE TABLE department (
    dname     VARCHAR(16),
    dnumber   INT PRIMARY KEY,
    mgrsrno   INT,
    mgrstartd DATE
);

INSERT INTO department
VALUES ('RESEARCH', 4, 495823, '20-APR-99'),
       ('ADMIN', 1, 133100, '06-JAN-88'),
       ('PROJECT', 2, 216852, '17-JUL-99'),
       ('ACADEMIC', 3, 315152, '20-DEC-89');

-- dept_locations
CREATE TABLE dept_locations (
    dnumber   INT,
    dlocation VARCHAR(16)
);

INSERT INTO dept_locations
VALUES (2, 'SINGAPORE'),
       (1, 'INDIA'),
       (4, 'QUUENSLAND'),
       (3, 'LONDON');

-- project
CREATE TABLE project (
    pname     VARCHAR(16),
    pnumber   INT PRIMARY KEY,
    plocation VARCHAR(16),
    dnum      INT
);

INSERT INTO project
VALUES ('NETWORKING', 11, 'KOREA', 4),
       ('BIO INFORMATICS', 19, 'SOUTH AFRICA', 3),
       ('LINUX', 17, 'INDIA', 2);

-- works_on
CREATE TABLE works_on (
    esrno INT,
    pno   INT,
    hours NUMERIC(3, 2)
);

INSERT INTO works_on
VALUES (315152, 19, 1.25),
       (334548, 19, 3.28),
       (215485, 17, 1.25),
       (295485, 17, 5.35),
       (334548, 19, 2.54),
       (295485, 17, 7.2),
       (216852, 17, 2.41),
       (334524, 19, 3.24),
       (295485, 17, 1.36),
       (495823, 11, 2.36),
       (215152, 17, 1.25),
       (495823, 11, 3.14),
       (315152, 19, 2.05),
       (334548, 19, 2.5);

ALTER TABLE employee
    ADD CONSTRAINT fk_mgrsrno_esrno
        FOREIGN KEY (mgrsrno)
            REFERENCES employee (esrno);

ALTER TABLE employee
    ADD CONSTRAINT fk_dno_dnumber
        FOREIGN KEY (dno)
            REFERENCES department (dnumber);

ALTER TABLE department
    ADD CONSTRAINT fk_mgrsrno_esrno
        FOREIGN KEY (mgrsrno)
            REFERENCES employee (esrno);

ALTER TABLE dept_locations
    ADD CONSTRAINT fk_dnumber_dnumber
        FOREIGN KEY (dnumber)
            REFERENCES department (dnumber);

ALTER TABLE project
    ADD CONSTRAINT fk_dnum_dnumber
        FOREIGN KEY (dnum)
            REFERENCES department (dnumber);

ALTER TABLE works_on
    ADD CONSTRAINT fk_esrno_esrno
        FOREIGN KEY (esrno)
            REFERENCES employee (esrno);

ALTER TABLE works_on
    ADD CONSTRAINT fk_pno_pnumber
        FOREIGN KEY (pno)
            REFERENCES project (pnumber);
