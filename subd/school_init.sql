DROP DATABASE IF EXISTS school;
CREATE DATABASE school;
USE school;

CREATE TABLE Students(
	Id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(150) NOT NULL,
	Num INTEGER NOT NULL,
	ClassNum INTEGER NOT NULL,
	ClassLetter CHAR(1) NOT NULL,
	Birthday DATE,
	EGN CHAR(10),
	EntranceExamResult NUMERIC(3,2)
);

CREATE TABLE Subjects(
	Id INTEGER NOT NULL AUTO_INCREMENT,
	Name VARCHAR(100),
	
	PRIMARY KEY(Id)
);

CREATE TABLE StudentMarks(
	StudentId INTEGER NOT NULL,
	SubjectId INTEGER NOT NULL,
	ExamDate DATETIME NOT NULL,
	Mark NUMERIC(3,2) NOT NULL,
	
	PRIMARY KEY( StudentId, SubjectId, ExamDate ),
	FOREIGN KEY (StudentId) REFERENCES Students(Id),
	FOREIGN KEY (SubjectId) REFERENCES Subjects(Id)
);

CREATE TABLE MarkWords(
	RangeStart NUMERIC(3,2) NOT NULL,
	RangeEnd NUMERIC(3,2) NOT NULL,
	MarkAsWord VARCHAR(15),
	
	PRIMARY KEY(RangeStart, RangeEnd)
);

INSERT INTO Students(Id, Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 101, 'Zara', 10, 11, 'A', '1999-02-28', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Iskren', 15, 10, 'B', '2000-02-29', '0042294120' );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Pandora', 20, 11, 'B', '2000-05-01', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Fidora', 20, 10, 'A', '1999-12-25', '9912256301' );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Bill', 1, 10, 'V', '2002-06-11', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Roman', 1, 10, 'G', '2002-06-11', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'John', 1, 10, 'G', '2002-06-11', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Hai', 1, 10, 'V', '2002-06-11', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Wu Zetian', 1, 9, 'A', '2002-06-11', NULL );
INSERT INTO Students(Name, Num, ClassNum, ClassLetter, Birthday, EGN) VALUES( 'Alex', 1, 12, 'A', '2002-06-11', NULL );

INSERT INTO Subjects(Id, Name) VALUES( 11, 'AE' );
INSERT INTO Subjects(Name) VALUES( 'BEL' );
INSERT INTO Subjects(Name) VALUES( 'Mat' );
INSERT INTO Subjects(Name) VALUES( 'SUBD' );

INSERT INTO StudentMarks VALUES( 101, 11, '2017-03-03', 5.75 );
INSERT INTO StudentMarks VALUES( 101, 11, '2017-03-31', 5.50 );
INSERT INTO StudentMarks VALUES( 102, 11, '2017-04-28', 5 );
INSERT INTO StudentMarks VALUES( 103, 12, '2017-04-28', 4 );
INSERT INTO StudentMarks VALUES( 104, 13, '2017-03-03', 5.25 );
INSERT INTO StudentMarks VALUES( 104, 13, '2017-04-07', 6 );
INSERT INTO StudentMarks VALUES( 104, 11, '2017-04-07', 4.50 );
INSERT INTO StudentMarks VALUES( 105, 14, '2017-04-07', 3 );
INSERT INTO StudentMarks VALUES( 106, 14, '2017-04-07', 4.15 );
INSERT INTO StudentMarks VALUES( 107, 14, '2017-04-07', 5.90 );
INSERT INTO StudentMarks VALUES( 108, 14, '2017-04-07', 3.45 );
INSERT INTO StudentMarks VALUES( 109, 14, '2017-04-07', 2.20 );
INSERT INTO StudentMarks VALUES( 110, 14, '2017-04-07', 4.25 );
INSERT INTO StudentMarks VALUES( 108, 14, '2017-04-07', 2 );


INSERT INTO MarkWords VALUES( 2, 2.50, 'F' );
INSERT INTO MarkWords VALUES( 2.50, 3.50, 'D' );
INSERT INTO MarkWords VALUES( 3.50, 4.50, 'C' );
INSERT INTO MarkWords VALUES( 4.50, 5.50, 'B' );
INSERT INTO MarkWords VALUES( 5.50, 6, 'A' );