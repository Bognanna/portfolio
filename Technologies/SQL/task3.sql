--Ex.1
SELECT COUNT(student_id)AS liczba_ocen
FROM oceny
WHERE ocena IS NOT NULL;

--Ex.2
SELECT rok_akademicki, COUNT(student_id) AS liczba_ocen
FROM oceny
WHERE ocena IS NOT NULL
GROUP BY rok_akademicki
ORDER BY rok_akademicki;

--Ex.3
SELECT rok_akademicki, COUNT(student_id) AS liczba_ocen
FROM oceny
WHERE ocena IS NOT NULL
GROUP BY rok_akademicki
ORDER BY liczba_ocen DESC
FETCH FIRST 1 ROWS ONLY;

SELECT rodzaj_semestru, COUNT(student_id) AS liczba_ocen
FROM oceny
WHERE rok_akademicki = '2006/07' AND ocena IS NOT NULL
GROUP BY rodzaj_semestru
ORDER BY liczba_ocen DESC;

--Ex.4
WITH kategorie AS(
    SELECT student_id, 
    CASE
        WHEN ocena >= 4.5 THEN 'oceny wybitne'
        WHEN ocena >= 3.5 THEN 'oceny �rednie'
        ELSE 'oceny slabe'
    END AS label
    FROM oceny)
SELECT k.label AS kategoria, COUNT(s.ocena) AS liczba_ocen
FROM oceny s JOIN kategorie k USING(student_id)
WHERE rok_akademicki = '2006/07' AND rodzaj_semestru = 'zimowy' AND ocena IS NOT NULL
GROUP BY k.label
ORDER BY liczba_ocen DESC;

SELECT  
    CASE
        WHEN ocena >= 4.5 THEN 'oceny wybitne'
        WHEN ocena >= 3.5 THEN 'oceny �rednie'
        ELSE 'oceny slabe'
    END AS label, COUNT(student_id) AS liczba_ocen
FROM oceny
WHERE rok_akademicki = '2006/07' AND rodzaj_semestru = 'zimowy' AND ocena IS NOT NULL
GROUP BY label
ORDER BY liczba_ocen DESC;

--Ex.5
SELECT student_id, TO_CHAR(AVG(ocena),'9.99') AS �rednia_ocen
FROM oceny
WHERE rok_akademicki = '2006/07' AND rodzaj_semestru = 'zimowy' AND ocena IS NOT NULL
GROUP BY student_id
ORDER BY AVG(ocena) DESC
FETCH FIRST 10 ROWS ONLY;

SELECT student_id, TO_CHAR(AVG(ocena),'9.99') AS �rednia_ocen
FROM oceny
WHERE rok_akademicki = '2006/07' AND rodzaj_semestru = 'zimowy' AND ocena IS NOT NULL
GROUP BY student_id
ORDER BY AVG(ocena)
FETCH FIRST 10 ROWS ONLY;   

--Ex.6
SELECT k.nazwa AS top_3_kierunki, k.symbol, TO_CHAR(AVG(o.ocena), '9.99') AS �renida_ocen
FROM oceny o JOIN studenci s USING(student_id)
    JOIN kierunki_studiow k ON k.symbol = s.kierunek
WHERE rok_akademicki = '2006/07' AND rodzaj_semestru = 'zimowy' AND ocena IS NOT NULL
GROUP BY k.nazwa, k.symbol
ORDER BY AVG(o.ocena) DESC
FETCH FIRST 3 ROWS ONLY;