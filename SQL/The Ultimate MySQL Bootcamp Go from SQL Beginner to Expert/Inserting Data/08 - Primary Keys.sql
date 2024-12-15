CREATE TABLE unique_cats (
    cat_id  INT             NOT NULL    PRIMARY KEY,
    name    VARCHAR(50),
    age     INT
);

INSERT INTO unique_cats (cat_id, name, age)
VALUES  (1, 'bingo', 2),
        (2, 'bongo', 3),
        (3, 'bongo', 3),
        (999, 'bongo', 3);