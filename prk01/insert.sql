CREATE TABLE abteilung (
	nr varchar(2),
	name varchar(30),

	PRIMARY KEY(nr)
);

CREATE TABLE person (
	nr int,
	name varchar(20),
 	vorname varchar(20),
        geburt date,
	abteilungnr varchar(2) REFERENCES abteilung(nr),
	gehalt numeric(10,2),
	ort varchar(20),

	PRIMARY KEY(nr)
);

CREATE TABLE import (
	nr varchar(30),
        ort varchar(30),
        geburt varchar(30),
        name varchar(30),
        vorname varchar(30),
        abteilungname varchar(30),
        abteilungnr varchar(30),
	gehalt varchar(30)
);

\copy import from 'dbsnam-utf8.csv' delimiter ';'

INSERT INTO abteilung (nr, name) SELECT DISTINCT abteilungnr, abteilungname FROM import;
INSERT INTO person (nr, name, vorname, geburt, abteilungnr, gehalt, ort) SELECT CAST(nr AS INT), name, vorname, CAST(geburt AS DATE), abteilungnr, CAST(gehalt AS FLOAT), ort FROM import;
