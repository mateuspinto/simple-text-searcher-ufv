#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tst.h"
#include "adt/characterQueue.h"

int main(){
    /*
    tst_node * tst = NULL;
    char palavra[20];

    palavra[0] = '\0';

    strcpy(palavra, "Mateus\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Mat\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Jorge\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Adolfinho\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Bolacha\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Deus\0");
    tst_node_insertWord(&tst, palavra);

    tst_node_goThrough(&tst);

    */

    characterQueue * fila;
    char a = 'S';

    characterQueue_startQueue(&fila);
    characterQueue_queue(&fila, &a);
    characterQueue_queue(&fila, &a);

    characterQueue_clean(&fila);

    printf("%c\n", characterQueue_unqueue(&fila));
    printf("%c\n", characterQueue_unqueue(&fila));
    printf("%c\n", characterQueue_unqueue(&fila));
    printf("%c\n", characterQueue_unqueue(&fila));

    characterQueue_queue(&fila, &a);
    printf("%c\n", characterQueue_unqueue(&fila));
    printf("%c\n", characterQueue_unqueue(&fila));
    return 1;
}
