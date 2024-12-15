CREATE TABLE unique_cats2 (
    cat_id  INT             PRIMARY KEY,
    name    VARCHAR(50),
    age     INT
);

INSERT INTO unique_cats2 (cat_id, name, age) VALUES (1, 'Oingo', 2);

CREATE TABLE unique_cats3 (
    cat_id  INT             PRIMARY KEY AUTO_INCREMENT,
    name    VARCHAR(50),
    age     INT
);

INSERT INTO unique_cats3 (name, age) VALUES ('Boingo', 1);

INSERT INTO unique_cats3 (name, age)
VALUES  ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1),
        ('Boingo', 1);

INSERT INTO unique_cats3 () VALUES (), (), ();