CREATE TABLE employees (
    id              INT             AUTO_INCREMENT  PRIMARY KEY,
    last_name       VARCHAR(100)    NOT NULL,
    first_name      VARCHAR(100)    NOT NULL,
    middle_name     VARCHAR(100),
    age             INT             NOT NULL,
    current_status  VARCHAR(100)    NOT NULL        DEFAULT 'employed'
);

INSERT INTO employees (first_name, last_name, age)
VALUES  ('thomas', 'chickenman', 87),
        ('thomas', 'chickenman', 87),
        ('thomas', 'chickenman', 87);