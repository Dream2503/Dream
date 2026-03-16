-- Q1. Create the following tables
CREATE TABLE region (
    region_id   SMALLINT,
    region_name VARCHAR(25)
);

CREATE TABLE countries (
    country_id   VARCHAR(2),
    country_name VARCHAR(40),
    region_id    SMALLINT
);

CREATE TABLE locations (
    location_id    INT,
    street_address VARCHAR(40),
    postal_code    VARCHAR(40),
    city           VARCHAR(30),
    state_province VARCHAR(25),
    country_id     VARCHAR(2)
);

CREATE TABLE departments (
    department_id   INT,
    department_name VARCHAR(30),
    manager_id      INT,
    location_id     INT
);

CREATE TABLE jobs (
    job_id     VARCHAR(10),
    job_title  VARCHAR(35),
    min_salary NUMERIC(8, 2),
    max_salary NUMERIC(8, 2)
);

CREATE TABLE job_history (
    employee_id   BIGINT,
    start_date    DATE,
    end_date      DATE,
    job_id        VARCHAR(10),
    department_id INT
);

CREATE TABLE employees (
    employee_id    INT,
    first_name     VARCHAR(20),
    last_name      CHAR(25),
    email          VARCHAR(25),
    phone_number   VARCHAR(20),
    hire_date      DATE,
    job_id         VARCHAR(10),
    salary         NUMERIC(8, 2),
    commission_pct NUMERIC(2, 2),
    manager_id     BIGINT,
    department_id  INT
);

-- Q2. Describe the structure of all the tables created in Q1.
SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'region';

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'countries';

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'locations';

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'departments';

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'jobs';

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'job_history';

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'employees';

/* Q3. Alter the locations table to add two new columns
       Zipcode number (2)
       Street_no varchar2 (50)
*/
ALTER TABLE locations
    ADD zipcode   SMALLINT,
    ADD street_no VARCHAR(50);

-- Q4. Alter the locations table to increase the size of the columns zipcode and street_add in a single query.
ALTER TABLE locations
    ALTER zipcode TYPE VARCHAR(8),
    ALTER street_address TYPE VARCHAR(60);

-- Q5. Drop the column zipcode and see the changes.
ALTER TABLE locations
    DROP zipcode;

-- Q6. Alter the table location to rename the column street_no to street_code and see the changes.
ALTER TABLE locations
    RENAME street_no TO street_code;

SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'locations';

-- Q7. Rename the table location to sit_location.
ALTER TABLE locations
    RENAME TO "sit_location";

-- Q8. Alter the Employees table to modify last_name from char to varchar2.
ALTER TABLE employees
    ALTER last_name TYPE VARCHAR(25);

-- Q9. Alter the Employees table to increase the size of the column Employee_id to 10.
ALTER TABLE employees
    ALTER employee_id TYPE BIGINT;

-- Q10. Alter the Employees table to decrease the size of the column last_name to 20.
ALTER TABLE employees
    ALTER last_name TYPE VARCHAR(20);

-- Q11. Alter the Employees table to decrease the size of the column phone_number to 18.
ALTER TABLE employees
    ALTER phone_number TYPE VARCHAR(18);

-- Q12. Add a new column ANNSAL in employees table.
ALTER TABLE employees
    ADD annsal NUMERIC(8, 2);

-- Q13. Show tables on your schema through tab and user_tables.
SELECT table_name
FROM information_schema.tables
WHERE table_schema = 'public';

-- Q14. Alter the above table to decrease the size of the column last_name to 24.
ALTER TABLE employees
    ALTER last_name TYPE VARCHAR(24);

-- Q15. Drop the column annsal from the table.
ALTER TABLE employees
    DROP annsal;

-- Q16. Modify the department table to increase the size of Manager_ID column to 12.
ALTER TABLE departments
    ALTER manager_id TYPE BIGINT;

-- Q17. Drop the column street_code of sit_locations table.
ALTER TABLE sit_location
    DROP street_code;

-- Q18. Rename the sit_location table to Locations.
ALTER TABLE sit_location
    RENAME TO "locations";

-- Q19. See the structural changes of department table.
SELECT column_name, data_type
FROM information_schema.columns
WHERE table_name = 'departments';
