-----------------------------------------------------------------
-----------------------------------------------------------------
--						ZADANIA PRODUKTY
-----------------------------------------------------------------
-----------------------------------------------------------------

--Rozszerzone Grupowanie

-- ******** TASK 1 **********
-- ********* CUBE ***********
SELECT Produkty.kategoria, Produkcja.rok, sum(Produkcja.ilosc_sprzed) AS sprzedano
FROM Produkcja LEFT JOIN Produkty ON  Produkcja.PRODUKT_ID = Produkty.PRODUKT_ID
GROUP BY CUBE(Produkty.kategoria, Produkcja.rok)
ORDER BY kategoria, rok;

-- ******** TASK 2 **********
-- ******** ROLLUP **********
SELECT pty.kategoria, pcja.miesiac, pcja.rok, sum(pcja.ilosc_sprzed) as sprzedano
FROM Produkcja pcja 
LEFT JOIN Produkty pty ON  pcja.PRODUKT_ID = pty.PRODUKT_ID
GROUP BY ROLLUP(pty.kategoria, pcja.miesiac, pcja.rok);

-- ******** TASK 3 **********
-- ******* GROUPING *********
SELECT pty.kategoria, pcja.miesiac, pcja.rok, sum(pcja.ilosc_sprzed) as "sprzedano",
 GROUPING(pty.KATEGORIA) as "sum kat", GROUPING(pcja.MIESIAC) as "sum mies", GROUPING(pcja.rok) as "sum all"
FROM Produkcja pcja 
LEFT JOIN Produkty pty ON  pcja.PRODUKT_ID = pty.PRODUKT_ID
GROUP BY ROLLUP(pcja.rok, pcja.miesiac, pty.kategoria);

-- ******** TASK 4 **********
-- ***** GROUPING SETS ******
SELECT pty.nazwa, pty.kategoria, pcja.rok, sum(pcja.ilosc_sprzed) as "sprzedano"
FROM Produkcja pcja 
RIGHT JOIN Produkty pty ON  pcja.PRODUKT_ID = pty.PRODUKT_ID
GROUP BY GROUPING SETS((pty.nazwa, pcja.rok), (pty.kategoria, pcja.rok))
ORDER BY pty.nazwa, pty.KATEGORIA, pcja.rok;

--Funkcje analityczne

-- ******** TASK 5 **********
-- ********* RANK ***********
select pty.kategoria, sum(pcja.ilosc_sprzed), rank() OVER (
    partition by pty.kategoria
    order by sum(pcja.ilosc_sprzed) DESC
) pozycja
from produkcja pcja left join produkty pty on (pcja.produkt_id = pty.produkt_id)
where pcja.rok = '2001'
group by pty.KATEGORIA;

-- ******** TASK 6 **********
-- ********* RANK ***********
select nazwa, kategoria, sprzedano, pozycja
from (
    select pty.nazwa, pty.kategoria, sum(pcja.ilosc_sprzed) sprzedano, rank() OVER (
        partition by pty.kategoria
        order by sum(pcja.ilosc_sprzed) DESC
    ) pozycja
    from produkcja pcja left join produkty pty on (pcja.produkt_id = pty.produkt_id)
    group by pty.kategoria, pty.nazwa
)
where pozycja = '1';

-- ******** TASK 7 **********
-- *******  WINDOWS *********
select pty.kategoria, pcja.rok, sum(pcja.ILOSC_SPRZED) "sprzedaz roczna",
max(sum(pcja.ILOSC_SPRZED)) over (
    PARTITION by pty.KATEGORIA
    order by pcja.rok
    range between unbounded preceding and unbounded following
    ) "max sprzedaz roczna"
from produkcja pcja left join produkty pty on (pcja.produkt_id = pty.produkt_id)
group by pty.kategoria, pcja.rok;


-- ******** TASK 8 **********
-- *******  WINDOWS *********
select pty.nazwa, pcja.miesiac, pcja.rok, pcja.ilosc_prod,
sum(pcja.ILOSC_PROD) over (order by pcja.rok, pcja.miesiac) "cum produkcja" 
from produkcja pcja left join produkty pty on (pcja.produkt_id = pty.produkt_id)
where pty.nazwa = 'fotel A';

-----------------------------------------------------------------
-----------------------------------------------------------------
--						ZADANIA KONTA W BANKU
-----------------------------------------------------------------
-----------------------------------------------------------------

--Funkcje analityczne

-- ******** TASK 1 **********
-- ********* RANK ***********
select nr_konta, sum(kwota), 
rank () over (
    order by sum(kwota) desc
) rank
from transakcje
group by nr_konta;

-- ******** TASK 2 **********
-- ********* RANK ***********
select ntile(4) over (
    order by data
) ntile, kwota, data, kategoria
from transakcje
where nr_konta = '11-11111111';

-- ******** TASK 3 **********
-- ********* RANK ***********
select NR_KONTA, kwota, data, ranking
from (
    select nr_konta, kwota, data,
    rank () over (
        PARTITION by NR_KONTA
        order by data ASC
    ) ranking
    from TRANSAKCJE
) where ranking = '1';

-- ******** TASK 4 **********
-- ********* RANK ***********