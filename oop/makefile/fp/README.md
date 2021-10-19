Едно n-цифрено число ще наричаме "взаимнопросто с фактор m" (m<=n) ако: <br>
n = p<sub>1</sub>\*m + q<sub>1</sub>
  1. m = 1 -> (a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>) = 1, където a<sub>1</sub>,...,a<sub>n</sub> са цифрите на даденото число  
  2. m > 1 -> (a<sub>1</sub>...a<sub>m</sub>, a<sub>m+1</sub>...a<sub>2m</sub>, ..., a<sub>(p-1)m+1</sub>...a<sub>pm</sub>, a<sub>pm+1</sub>...a<sub>n</sub>) = 1. После трябва 
да повторим това уравнение, но за m-цифрено число с фактор q (очевидно, m може да се разпадне по подобен на горепоказания начин (m = p<sub>2</sub>\*q<sub>1</sub> + q<sub>2</sub>))
и така докато не достигнем базовия случай (1. )

Да се напише програма, която приема n-цифрено число и намира дали е "взаимнопросто с фактор m". 