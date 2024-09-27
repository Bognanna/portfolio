--TASK 1

--Ex.1
SELECT COUNT(student_id) AS "LICZBA_STUDENT�W"
FROM STUDENCI;

--Ex.2
SELECT nazwa AS "KIERUNEK", symbol
FROM kierunki_studiow
ORDER BY nazwa;

--Ex.3
SELECT k.nazwa AS "KIERUNEK", k.symbol, COUNT(s.student_id) AS "STUDENT�W"
FROM kierunki_studiow k JOIN studenci s 
    ON s.kierunek = k.symbol
GROUP BY k.nazwa, k.symbol
ORDER BY k.nazwa;

--Ex.4
SELECT k.nazwa AS "KIERUNEK", k.symbol, COUNT(s.student_id) AS "STUDENT�W"
FROM kierunki_studiow k JOIN studenci s 
    ON s.kierunek = k.symbol
GROUP BY k.nazwa, k.symbol
ORDER BY COUNT(s.student_id) DESC
FETCH FIRST 3 ROWS ONLY;

--Ex.5
SELECT r.nazwa AS "RODZAJ_STUDIOW", r.symbol, COUNT(s.student_id) AS "STUDENT�W"
FROM rodzaje_studiow r JOIN kierunki_studiow k 
    ON k.rodzaj_studiow = r.symbol
    JOIN studenci s
    ON k.symbol = s.kierunek
GROUP BY r.nazwa, r.symbol
ORDER BY r.nazwa;

SELECT ks.nazwa AS "KATEGORIA_STUDIOW", ks.symbol, COUNT(s.student_id) AS "STUDENT�W"
FROM kategorie_studiow ks JOIN rodzaje_studiow r 
    ON ks.symbol = r.kategoria_studiow
    JOIN kierunki_studiow k 
    ON k.rodzaj_studiow = r.symbol
    JOIN studenci s
    ON k.symbol = s.kierunek
GROUP BY ks.nazwa, ks.symbol
ORDER BY ks.nazwa;