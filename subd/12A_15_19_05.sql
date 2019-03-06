DROP DATABASE IF EXISTS real_estate;
CREATE DATABASE real_estate;

USE real_estate;

CREATE TABLE Brokers(
	id INTEGER NOT NULL,
    name VARCHAR(50) NOT NULL,
    age INTEGER NOT NULL,
    phone VARCHAR(16) NOT NULL,
    
    PRIMARY KEY(id)
);

CREATE TABLE Accommodations(
	id INTEGER AUTO_INCREMENT NOT NULL,
    broker_id INTEGER NOT NULL,
    price INTEGER NOT NULL,
    size INTEGER NOT NULL,
    location ENUM('Lulin', 'Mladost', 'Lozenets', 'Centre', 'Poligona'),
    
    PRIMARY KEY(id),
    FOREIGN KEY(broker_id) REFERENCES Brokers(id)
);

INSERT INTO Brokers VALUES (1, 'Peshislav', 23, '+359 88 1234 432');
INSERT INTO Brokers VALUES (2, 'Iva', 52, '+359 87 8888 777');
INSERT INTO Brokers VALUES (3, 'Alexo', 19, '+359 88 4567 765');

INSERT INTO Accommodations VALUES (1, 1, 1356, 200, 'Lulin');
INSERT INTO Accommodations VALUES (2, 2, 222, 300, 'Mladost');
INSERT INTO Accommodations VALUES (3, 3, 401, 150, 'Lozenets');
INSERT INTO Accommodations VALUES (4, 1, 536, 52, 'Centre');
INSERT INTO Accommodations VALUES (5, 2, 324, 400, 'Poligona');
INSERT INTO Accommodations VALUES (6, 3, 606, 65, 'Mladost');
INSERT INTO Accommodations VALUES (7, 2, 666, 69, 'Poligona');

SELECT name, phone, price, size, location FROM Brokers
LEFT JOIN Accommodations ON broker_id = Brokers.id
WHERE name LIKE 'Alex%';

SELECT name, phone, location FROM Brokers
LEFT JOIN Accommodations ON broker_id = Brokers.id
WHERE location = 'Mladost';

SELECT name, phone, price, size FROM Brokers
LEFT JOIN Accommodations ON broker_id = Brokers.id
WHERE size BETWEEN 50 AND 70 AND price BETWEEN 500 AND 700
ORDER BY price;

SELECT name, phone, price, size FROM Brokers
LEFT JOIN Accommodations ON broker_id = Brokers.id
WHERE size BETWEEN 50 AND 70 AND price BETWEEN 500 AND 700 
		AND (location = 'Mladost' OR location = 'Izgrev' OR location = 'Poligona')
ORDER BY price/size;

