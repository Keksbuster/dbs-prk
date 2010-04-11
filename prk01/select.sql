--Aus welchem Ort kommen wieviele Mitarbeiter?
SELECT ort, COUNT(nr) FROM person GROUP BY ort;

--Wie heißt die Abteilung, in der Norbert Herrling arbeitet?
SELECT person.nr, abteilung.name FROM person, abteilung WHERE person.vorname = 'Norbert' AND person.name = 'Herrling' AND person.abteilungnr = abteilung.nr;

-- Was ist das Durchschnittsgehalt je Abteilung?
SELECT abteilungnr, CAST(avg(gehalt) AS numeric(10,2)) FROM person GROUP BY abteilungnr;
