/*
 * DBS-Praktikum Aufgabe 2
 *    Header abstraktes DB-Interface
 *
 * Christoph Dalitz
 * Hochschule Niederrhein
 * 2010/03/19
 */

#ifndef DB_H
#define DB_H

/*Datenbank erstellen*/
void db_create();

/*Datenbank-Login*/
/* rc: 0 = ok, 1 = error */
int db_login(char* user, char* password, char* host, char* dbname);

/*Datenbank-Logout*/
void db_logout();

/*Transaktionsbefehle*/
/* rc: 0 = ok, 1 = error */
int db_begin();
int db_commit();
int db_rollback();

/*Pruefen, ob Matrikelnummer schon vorhanden*/
/* rc: 0 = noch nicht da, 1 = schon da, -1 = error */
int db_checkmtnr(char* mtnr);

/*Einfuegen Datensatz*/
/* rc: 0 = ok, 1 = error */
int db_insert(char* mtnr, char* vorname, char* nachname, char* geburt);

/*Loeschen des kompletten Tabelleninhalts*/
/* rc: 0 = ok, 1 = error */
int db_delete();

#endif /*DB_H*/