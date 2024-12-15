INSERT INTO cats (name) VALUES ("Bean"), ("Todd");

INSERT INTO cats () VALUES ();

CREATE TABLE cats2 (
    name    VARCHAR(50) NOT NULL,
    age     INT         NOT NULL
);

INSERT INTO cats2 (name, age) VALUES ("Bilbo", 19);