#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tst.h"
#include "adt/characterBuffer.h"

//#include "debug.h"

int main(){

    tst_node * tst = NULL;
    char palavra[20]; 
    characterBuffer * buffer;
    characterBuffer * aux;


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
    tst_node_goThrough(&tst);

    /* characterBuffer_startBuffer(&buffer);
    aux = buffer;

    characterBuffer_buff(&buffer, 'a');
    characterBuffer_buff(&buffer, 'a');
    characterBuffer_buff(&buffer, 'a');
    characterBuffer_buff(&buffer, 'a');

    while(characterBuffer_notEmpty(&aux)){
        printf("beibe - %c\n", characterBuffer_returnCharacter(&aux));
        aux = aux->next;
    }

    while(characterBuffer_notEmpty(&buffer))
        printf("%c\n", characterBuffer_unbuff(&buffer));


    printf("beibe - %c\n", characterBuffer_returnCharacter(&aux)); */

    return 1;
}
