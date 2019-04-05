#include <stdio.h>
#include <stdlib.h>

#include "characterBuffer.h"

int characterBuffer_startBuffer(characterBuffer ** node){
    (*node) = malloc(sizeof(characterBuffer));

    if((*node) == NULL)
        return 0;

    (**node).next = NULL;

    #ifdef DEBUG
        printf("DEBUG == characterBuffer -- BUFFER DE PALAVRAS CRIADO\n");
    #endif

    return 1;
}

int characterBuffer_createNode(characterBuffer **node, char character){
    (*node) = malloc(sizeof(characterBuffer));

    if((*node) == NULL)
        return 0;

    (**node).next = NULL;
    (**node).character = character;

    return 1;
}

int characterBuffer_buff(characterBuffer **node, char character){
    if ((**node).next == NULL){
        return characterBuffer_createNode(&((**node).next), character);
    }

    characterBuffer_buff(&((**node).next), character);
}

char characterBuffer_unbuff(characterBuffer **node){
    char aux;
    characterBuffer * toFree = NULL;

    if ((**node).next == NULL){
        return '\0';
    }

    aux = ((**node).next) -> character;
    toFree = *node;

    *node = (**node).next;

    free(toFree);

    return aux;
}

int characterBuffer_clear(characterBuffer **node){
    while((**node).next != NULL){
        characterBuffer_unbuff(node);
    }

    return 1;
}

int characterBuffer_notEmpty(characterBuffer **node){
    if ((**node).next == NULL)
        return 0;
    return 1;
}

char characterBuffer_returnCharacter(characterBuffer **node){
    if ((**node).next == NULL)
        return '\0';
    return (**node).next -> character;
}
