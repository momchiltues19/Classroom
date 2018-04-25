USE school;

SELECT Max(sm.Mark)
FROM StudentMarks sm
LEFT JOIN Subjects sub
ON sm.SubjectId = sub.Id
WHERE sub.Name = 'AE';

SELECT s.Name, ROUND(AVG(sm.Mark), 3)
FROM StudentMarks sm
LEFT JOIN Students s
ON sm.StudentId = s.Id
GROUP BY s.Id, s.Name;

SELECT s.ClassLetter, AVG(sm.Mark)
FROM StudentMarks sm
LEFT JOIN Students s
ON sm.StudentId = s.Id
WHERE s.ClassNum = 10
GROUP BY s.ClassLetter;

SELECT COUNT(sm.Mark)
FROM StudentMarks sm
LEFT JOIN Subjects sub
ON sm.SubjectId = sub.Id
WHERE sub.Name = 'AE' AND sm.Mark >= 5.50;
