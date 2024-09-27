--Ex.1
SELECT m.wojewodztwo, COUNT(s.student_id)
FROM miasta m JOIN studenci s USING(miasto_id)
GROUP BY m.wojewodztwo
ORDER BY m.wojewodztwo;

--Ex.2
SELECT m.wojewodztwo, COUNT(s.student_id)
FROM miasta m JOIN studenci s USING(miasto_id)
GROUP BY m.wojewodztwo
ORDER BY COUNT(s.student_id)DESC
FETCH FIRST 5 ROWS ONLY;

--Ex.3
SELECT m.wojewodztwo, m.nazwa, COUNT(s.student_id)
FROM miasta m JOIN studenci s USING(miasto_id)
WHERE m.wojewodztwo IN
    (SELECT m.wojewodztwo
        FROM miasta m JOIN studenci s USING(miasto_id)
        GROUP BY m.wojewodztwo
        ORDER BY COUNT(s.student_id)DESC
        FETCH FIRST 5 ROWS ONLY)
GROUP BY m.wojewodztwo, m.nazwa
ORDER BY m.wojewodztwo, m.nazwa;

--Ex.4
WITH pom1 AS(
    SELECT m.wojewodztwo, COUNT(s.student_id) AS stud_w_woj
    FROM miasta m JOIN studenci s USING(miasto_id)
    GROUP BY m.wojewodztwo)
SELECT m.wojewodztwo, m.nazwa, COUNT(s.student_id) AS "stud_w_miescie", p.stud_w_woj, ROUND(COUNT(s.student_id)/p.stud_w_woj * 100,2) AS procentowo 
FROM miasta m JOIN studenci s 
    ON m.miasto_id = s.miasto_id
    JOIN pom1 p
    ON p.wojewodztwo = m.wojewodztwo
WHERE m.wojewodztwo IN
    (SELECT m.wojewodztwo
        FROM miasta m JOIN studenci s USING(miasto_id)
        GROUP BY m.wojewodztwo
        ORDER BY COUNT(s.student_id)DESC
        FETCH FIRST 5 ROWS ONLY)
GROUP BY m.wojewodztwo, m.nazwa, p.stud_w_woj
ORDER BY m.wojewodztwo, m.nazwa;

--EX.5
SELECT m.wojewodztwo, s.plec, COUNT(s.student_id)
FROM miasta m JOIN studenci s USING(miasto_id)
GROUP BY m.wojewodztwo, s.plec
ORDER BY m.wojewodztwo, s.plec;

--EX.6 NO IDEA
SELECT m.wojewodztwo, s.plec,(CASE WHEN(COUNT(s.student_id)IS NOT NULL) THEN (COUNT(s.student_id)) ELSE 0 END) AS studentow
FROM miasta m LEFT JOIN studenci s USING(miasto_id)
GROUP BY m.wojewodztwo, s.plec
ORDER BY m.wojewodztwo, s.plec;

--Ex.7
SELECT m.wojewodztwo, 
    SUM(CASE WHEN s.plec LIKE 'kobieta' THEN 1 ELSE 0 END) AS kobiety,
    SUM(CASE WHEN s.plec LIKE 'mê¿czyzna' THEN 1 ELSE 0 END) AS mê¿czyŸni,
    COUNT(s.student_id) AS razem
FROM miasta m JOIN studenci s USING(miasto_id)
GROUP BY m.wojewodztwo
ORDER BY m.wojewodztwo;