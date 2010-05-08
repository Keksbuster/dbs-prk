/*
 * DBS-Praktikum Aufgabe 2
 * main.c
 * 
 */

#include <stdio.h>
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
    if(argc <= 1){
        print_usage();
    }
    return 0;
}
