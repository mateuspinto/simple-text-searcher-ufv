#include <stdio.h>
#include <stdlib.h>

#include "characterQueue.h"

int characterQueue_startQueue(characterQueue ** node){
    (*node) = malloc(sizeof(characterQueue));

    if((*node) == NULL)
        return 0;

    (**node).next = NULL;
    return 1;
}

int characterQueue_createNode(characterQueue **node, char character){
    (*node) = malloc(sizeof(characterQueue));

    if((*node) == NULL)
        return 0;

    (**node).next = NULL;
    (**node).character = character;

    return 1;
}

int characterQueue_queue(characterQueue **node, char character){
    if ((**node).next == NULL){
        return characterQueue_createNode(&((**node).next), character);
    }

    characterQueue_queue(&((**node).next), character);
}

char characterQueue_unqueue(characterQueue **node){
    char aux;
    characterQueue * toFree = NULL;

    if ((**node).next == NULL){
        return '\0';
    }

    aux = ((**node).next) -> character;
    toFree = *node;

    *node = (**node).next;

    free(toFree);

    return aux;
}

int characterQueue_clean(characterQueue **node){
    while((**node).next != NULL){
        characterQueue_unqueue(node);
    }

    return 1;
}
