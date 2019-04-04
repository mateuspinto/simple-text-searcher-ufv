#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tst.h"

int main(){
    tst_node * tst = NULL;
    char palavra[20];

    palavra[0] = '\0';

    strcpy(palavra, "Mateus\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Mat\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Bola\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Bolacha\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Bola\0");
    tst_node_insertWord(&tst, palavra);

    return 1;
}
