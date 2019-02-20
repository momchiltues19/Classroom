DROP DATABASE weight_db;
CREATE DATABASE weight_db;

USE weight_db;

CREATE TABLE Person (
	id INTEGER AUTO_INCREMENT NOT NULL, 
	p_name VARCHAR(50) NOT NULL,
    age INTEGER,
    average_weight FLOAT DEFAULT 0,
    gender ENUM('M', 'F'),
    
    PRIMARY KEY (id)
);

CREATE TABLE Weight_data (
	id INTEGER NOT NULL, 
	created_at DATETIME,
    weight FLOAT,
    p_id INTEGER,
    
    PRIMARY KEY (id),
    FOREIGN KEY (p_id) REFERENCES Person(id)
);

INSERT INTO Person (id, p_name, age, gender) VALUES (1, 'Pesho', 18, 'M');
INSERT INTO Person (p_name, age, gender) VALUES ('Iva', 20, 'F');
INSERT INTO Person (p_name, age, gender) VALUES ('Rina', 24, 'F');
INSERT INTO Person (p_name, age, gender) VALUES ('Mitko', 30, 'M');

CREATE TRIGGER avg_weight
AFTER INSERT ON Weight_data 
FOR EACH ROW
	UPDATE Person SET average_weight = 
		(SELECT AVG(weight) FROM Weight_data WHERE p_id = NEW.p_id)
    WHERE NEW.p_id = Person.id;

INSERT INTO Weight_data VALUES (1, NOW(), 102, 1);
INSERT INTO Weight_data VALUES (2, NOW(), 34, 2);
INSERT INTO Weight_data VALUES (3, NOW(), 65, 3);
INSERT INTO Weight_data VALUES (4, NOW(), 83, 4);
INSERT INTO Weight_data VALUES (5, NOW(), 108, 1);
INSERT INTO Weight_data VALUES (6, DATE_FORMAT(NOW() ,'%Y-01-01'), 100, 1);
INSERT INTO Weight_data VALUES (7, DATE_FORMAT(NOW() ,'%Y-12-31'), 88, 1);

SELECT AVG(weight) FROM Weight_data
WHERE p_id = 1 AND created_at BETWEEN DATE_SUB(NOW(), INTERVAL 1 MONTH) AND NOW();

SELECT (first_w.weight - last_w.weight) FROM Weight_data first_w
LEFT JOIN Weight_data last_w ON last_w.created_at = DATE_FORMAT(NOW() ,'%Y-12-31') 
	AND first_w.p_id = 1 AND last_w.p_id = 1
WHERE first_w.created_at = DATE_FORMAT(NOW() ,'%Y-01-01');

SELECT AVG(weight) FROM Weight_data
LEFT JOIN Person ON Person.id = p_id
WHERE gender = 'F';

SELECT AVG(weight) FROM Weight_data
LEFT JOIN Person ON Person.id = p_id
WHERE gender = 'M';







