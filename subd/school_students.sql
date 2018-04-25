USE school;

SELECT Name,SubjectName,ExamDate,Mark
FROM marks m
INNER JOIN students s
ON s.Num = m.StudentNum AND s.Class = m.StudentClass
WHERE m.Mark > 5;  