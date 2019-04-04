#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tst.h"
#include "adt/characterQueue.h"

int main(){

    tst_node * tst = NULL;
    char palavra[20];
    characterQueue * queue;

    palavra[0] = '\0';

    strcpy(palavra, "Mateus\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Mat\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Jorge\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Adenor\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Bolacha\0");
    tst_node_insertWord(&tst, palavra);

    strcpy(palavra, "Junior\0");
    tst_node_insertWord(&tst, palavra);

    characterQueue_startQueue(&queue);

    tst_node_goThrough(&tst, &queue);


    return 1;
}
