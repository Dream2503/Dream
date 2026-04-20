BEGIN;

-- Create a table to store movie details with following column definition 
CREATE TABLE movies (
    "name"       VARCHAR(20),
    director     VARCHAR(20),
    actor        VARCHAR(20),
    actress      VARCHAR(20),
    budget       NUMERIC(10, 2),
    release_year INT,
    rating       INT
);

-- Q1. Insert at least 10 movie details.
INSERT INTO movies VALUES
('Inception', 'Chris Nolan', 'Leo DiCaprio', 'M. Cotillard', 16000000.00, 2010, 9),
('The Dark Knight', 'Chris Nolan', 'Christian Bale', 'M. Gyllenhaal', 18500000.00, 2008, 9),
('Avatar', 'James Cameron', 'Sam Worthington', 'Zoe Saldana', 23700000.00, 2009, 8),
('Interstellar', 'Chris Nolan', 'M. McConaughey', 'Anne Hathaway', 16500000.00, 2014, 9),
('The Matrix', 'Lana Wachowski', 'Keanu Reeves', 'C.A. Moss', 6300000.00, 1999, 9),
('Titanic', 'James Cameron', 'Leo DiCaprio', 'Kate Winslet', 20000000.00, 1997, 8),
('Mad Max Fury', 'George Miller', 'Tom Hardy', 'C. Theron', 15000000.00, 2015, 8),
('La La Land', 'Damien Chazelle', 'Ryan Gosling', 'Emma Stone', 3000000.00, 2016, 8),
('EEAAO', 'Daniel Kwan', 'Ke Huy Quan', 'Michelle Yeoh', 2500000.00, 2022, 8),
('Parasite', 'Bong Joon-ho', 'Song Kang-ho', 'Cho Yeo-jeong', 1140000.00, 2019, 9);

-- Q2. Display the details
SELECT * FROM movies;

-- Q3. Create a savepoint. 
SAVEPOINT sp1;

-Q4. Delete details of 5 movies. 
DELETE FROM movies
WHERE "name" IN (SELECT "name"
                 FROM movies
                 LIMIT 5);

-- Q5. Display the details
SELECT * FROM movies;

-- Q6. Add two more new movie details. 
INSERT INTO movies VALUES
('Inception', 'Chris Nolan', 'Leo DiCaprio', 'M. Cotillard', 16000000.00, 2010, 9),
('The Dark Knight', 'Chris Nolan', 'Christian Bale', 'M. Gyllenhaal', 18500000.00, 2008, 9);

-- Q7. Display the details
SELECT * FROM movies;

-- Q8. Rollback to savepoint created at line 3. 
ROLLBACK TO sp1;

-- Q9. Display the details
SELECT * FROM movies;

-- Q10. Add a column PRODUCER VARCHAR(20). 
ALTER TABLE movies
ADD COLUMN producer VARCHAR(20);

-- Q11. Display the details
SELECT * FROM movies;

-- Q12. Update the values for the newly added column
UPDATE movies
SET producer = 'Emma Thomas'
WHERE name = 'The Dark Knight';

UPDATE movies
SET producer = 'Emma Thomas'
WHERE name = 'Inception';

UPDATE movies
SET producer = 'James Cameron'
WHERE name = 'Titanic';

UPDATE movies
SET producer = 'Doug Mitchell'
WHERE name = 'Mad Max Fury';

UPDATE movies
SET producer = 'Fred Berger'
WHERE name = 'La La Land';

UPDATE movies
SET producer = 'Jonathan Wang'
WHERE name = 'EEAAO';

UPDATE movies
SET producer = 'Kwak Sin-ae'
WHERE name = 'Parasite';

-- Q13. Create a savepoint. 
SAVEPOINT sp2;

-- Q14. Display the details
SELECT * FROM movies;

-- Q15. Rollback to savepoint created at line 13. 
ROLLBACK TO sp2;

-- Q16. Display the details
SELECT * FROM movies;

-- Q17. Drop the newly added column
ALTER TABLE movies
DROP COLUMN producer;

-- Q18. Display the details
SELECT * FROM movies;

-- Q19. Delete all the movies whose ratings are below 3.
DELETE FROM movies
WHERE rating < 3;

-- Q20. Display the details
SELECT * FROM movies;

-- Q21. Make the changes permanent. 
COMMIT;

/*
Q22. Start a new transaction in read only mode. 
[hint: BEGIN TRANSACTION READ ONLY]
*/
BEGIN TRANSACTION READ ONLY;

-- Q23. Display the details
SELECT * FROM movies;

-- Q24. Delete all movie details
DELETE FROM movies;

-- Q25. Rollback the read only transaction.
ROLLBACK;
