drop table employee CASCADE;
drop table department CASCADE;
drop table dept_locations CASCADE;
drop table project CASCADE;
drop table works_on CASCADE;

-- employee
CREATE TABLE employee (
    ename VARCHAR(16) NOT NULL,
    esrno INT PRIMARY KEY CHECK (esrno BETWEEN 100000 AND 999999),
    bdate DATE CHECK (EXTRACT(YEAR FROM bdate) BETWEEN 1955 AND 1979),
    address VARCHAR(16),
    sex CHAR(1) DEFAULT 'M',
    salary INT CHECK (salary BETWEEN 20000 AND 40000),
    mgrsrno INT,
    dno INT
);

INSERT INTO employee
VALUES ('AJIT NAYAK', 133100, '1955-04-25', '73 BOSTON', 'M', 35000, NULL, 1),
       ('SATYA', 495823, '1966-07-17', '26 FINE OAK', 'M', 32770, 133100, 4),
       ('AJIT BEHERA', 315152, '1971-07-09', '10 KALINGA', 'M', 32802, 133100, 3),
       ('UMASHANKAR', 216852, '1967-07-17', '26 FINE OAK', 'M', 32770, 133100, 2),
       ('BHAGWAT', 215152, '1971-03-23', '55 FLORIDA', 'M', 32802, 216852, 2),
       ('MEENAKSHI', 334548, '1979-04-25', '73 BRIKLY', 'F', 25125, 315152, 3),
       ('JASWASI', 215485, '1979-08-12', '17 BOSTON', 'M', 20500, 495823, 4),
       ('NIHAR NAYAK', 334524, '1966-12-17', '73 DALLAS', 'M', 29105, 315152, 3),
       ('DEBASMITA', 295485, '1970-04-16', '1 QUEENS LAND', 'F', 20500, 216852, 2);

-- department
CREATE TABLE department (
    dname VARCHAR(16) CHECK (dname IN ('RESEARCH', 'ADMIN', 'PROJECT', 'ACADEMIC')),
    dnumber INT PRIMARY KEY CHECK (dnumber BETWEEN 1 AND 4),
    mgrsrno INT,
    mgrstartd DATE
);

INSERT INTO department 
VALUES ('RESEARCH', 4, 495823, '1999-04-20'),
       ('ADMIN', 1, 133100, '1988-01-06'),
       ('PROJECT', 2, 216852, '1999-07-17'),
       ('ACADEMIC', 3, 315152, '1999-12-20');

-- dept_locations
CREATE TABLE dept_locations (
    dnumber INT CHECK (dnumber BETWEEN 1 AND 4),
    dlocation VARCHAR(16) CHECK (dlocation IN ('SINGAPORE', 'INDIA', 'QUUENSLAND', 'LONDON'))
);

INSERT INTO dept_locations
VALUES (2, 'SINGAPORE'),
       (1, 'INDIA'),
       (4, 'QUUENSLAND'),
       (3, 'LONDON');

-- project
CREATE TABLE project (
    pname VARCHAR(16) CHECK (pname IN ('NETWORKING', 'BIO INFORMATICS', 'LINUX')),
    pnumber INT PRIMARY KEY,
    plocation VARCHAR(16) CHECK (plocation IN ('KOREA', 'SOUTH AFRICA', 'INDIA')),
    dnum INT
);

INSERT INTO project
VALUES ('NETWORKING', 11, 'KOREA', 4),
       ('BIO INFORMATICS',19, 'SOUTH AFRICA', 3),
       ('LINUX', 17, 'INDIA', 2);

-- works_on
CREATE TABLE works_on (
    esrno INT CHECK (esrno BETWEEN 100000 AND 999999),
    pno INT CHECK (pno > 0),
    hours NUMERIC(3, 2) CHECK (hours > 0)
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
