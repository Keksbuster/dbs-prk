/*
 * DBS-Praktikum Aufgabe 2
 * main.c
 * 
 */

#include <stdio.h>
#include <string.h>
#include "db.h"

void print_usage() {
    printf("Usage:\n");
    printf("\t dbimp [options] <infile>\n");
    printf("Options:\n");
    printf("\t-del delete table contents before import\n");
    printf("\t-u database user\n");
    printf("\t-p password\n");
    printf("\t-h database host\n");
    printf("\t-d database name\n");
}

int main(int argc, char** argv)
{
    int del = 0;
    char dbuser[50]="";
    char dbhost[50]="";
    char dbpass[50]="";
    char dbname[50]="";
    char filename[50]="";
    if(argc <= 1){
        print_usage();
    } else if(argc == 2) {
        strcpy(filename, argv[1]);
    } else {
        int i;
        for(i = 1; i < argc-1; i++) {
            char buffer[] = "-del";
            if(strcmp(buffer,argv[i]) == 0){
                del = 1;
                continue;
            }
            if(argv[i][0] == '-'){
                switch(argv[i][1]){
                    case 'u':
                        i++;
                        strcpy(dbuser, argv[i]);
                        break;
                    case 'p':
                        i++;
                        strcpy(dbpass, argv[i]);
                        break;
                    case 'h':
                        i++;
                        strcpy(dbhost, argv[i]);
                        break;
                    case 'd':
                        i++;
                        strcpy(dbname, argv[i]);
                        break;
                    default:
                        printf("Option not known: %s\n", argv[i]);
                        print_usage();
                        return 1;
                }
            }
        }
        strcpy(filename, argv[argc-1]);
    }
    printf("dbuser: %s\n", dbuser);
    printf("dbhost: %s\n", dbhost);
    printf("dbpass: %s\n", dbpass);
    printf("dbname: %s\n", dbname);
    printf("del: %d\n", del);
    printf("filename: %s\n", filename);
    return 0;
}
