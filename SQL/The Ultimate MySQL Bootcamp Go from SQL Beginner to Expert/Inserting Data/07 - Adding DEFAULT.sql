CREATE TABLE cats3 (
    name    VARCHAR(50) DEFAULT 'unknown',
    age     INT         DEFAULT -1
);

INSERT INTO cats3 (age) VALUES (2);

INSERT INTO cats3 () VALUES ();

INSERT INTO cats3 (name, age) VALUES (NULL, NULL);

CREATE TABLE cats4 (
    name    VARCHAR(50) NOT NULL    DEFAULT 'unknown',
    age     INT         NOT NULL    DEFAULT -1
);

INSERT INTO cats4 () VALUES ();