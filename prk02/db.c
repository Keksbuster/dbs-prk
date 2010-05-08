/*
 * DBS-Praktikum Aufgabe 2
 *    C-File abstraktes DB-Interface
 */

#include <libpq-fe.h>
#include <stdio.h>

PGconn* conn;
/*Datenbank-Login*/
/* rc: 0 = ok, 1 = error */
int db_login(char* user, char* password, char* host, char* dbname){
    /* Login */
    conn = PQconnectdb("dbname=dbname user=user password=password host=host");
    
    /* Fehlerüberprüfung */
    if (PQstatus(conn) == CONNECTION_BAD) {
        return 1;
    }
    return 0;
}

/*Datenbank-Logout*/
void db_logout(){
    PQfinish(conn);
}

/*Transaktionsbefehle*/
/* rc: 0 = ok, 1 = error */
int db_begin(){
    PGresult *res;
    
    res = PQexec(conn, "BEGIN TRANSACTION");
    
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        PQclear(res);
        return 0;
    }
    PQclear(res);
    return 1;
}

int db_commit(){
    PGresult *res;
    
    res = PQexec(conn, "COMMIT");
    
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        PQclear(res);
        return 0;
    }
    PQclear(res);
    return 1;
}

int db_rollback(){
    PGresult *res;
    
    res = PQexec(conn, "ROLLBACK");
    
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        PQclear(res);
        return 0;
    }
    PQclear(res);
    return 1;
}

/*Pruefen, ob Matrikelnummer schon vorhanden*/
/* rc: 0 = noch nicht da, 1 = schon da, -1 = error */
int db_checkmtnr(char* mtnr){
    PGresult *res;
    int i;
    
    res = PQexec(conn, "SELECT mtnr FROM student");
    
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        for(i = 0; i < PQntuples(res); i++) {
            if(PQgetvalue(res, i, 0) == mtnr){
                PQclear(res);
                return 1;
            }
        }
        PQclear(res);
        return 0;
    }
    else {
        PQclear(res);
        return -1;
    }
}    

/*Einfuegen Datensatz*/
/* rc: 0 = ok, 1 = error */
int db_insert(char* mtnr, char* vorname, char* nachname, char* geburt){
    PGresult *res;
    char buffer[100];
    
    sprintf(buffer, "INSERT INTO student (mtnr, vorname, nachname, geburt) VALUES (%s, %s, %s, %s)", mtnr, vorname, nachname, geburt);
    
    res = PQexec(conn, buffer);
    
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        PQclear(res);
        return 0;
    }
    PQclear(res);
    return 1;
}

/*Loeschen des kompletten Tabelleninhalts*/
/* rc: 0 = ok, 1 = error */
int db_delete(){
    PGresult *res;
    
    res = PQexec(conn, "DELETE * FROM student");
    
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        PQclear(res);
        return 0;
    }
    PQclear(res);
    return 1;
}    
