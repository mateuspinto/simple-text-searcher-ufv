#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "invertedChainedList.h"

int invertedChainedListStartList(invertedChainedList **node){
    (*node) = NULL;

    #ifdef DEBUG
        printf("DEBUG == invertedChainedList -- LISTA ENCADEADA CRIADA\n");
    #endif

    return 1;
}

int invertedChainedListCreateNode(invertedChainedList ** node, char * filename){

    (*node) = malloc(sizeof(invertedChainedList));

    if((*node)==NULL){
        return 0;
    }


    (**node).next = NULL;
    (**node).ocurrences = 1;

    strcpy((**node).filename, filename);

    return 1;
}

int invertedChainedIncrementOcurrence(invertedChainedList ** node){
    (** node).ocurrences++;
    return 1;
}


int invertedChainedListInsertNode(invertedChainedList ** node, char * filename){

    if((*node)==NULL){
        return invertedChainedListCreateNode(node, filename);
    }

    if(strcmp((**node).filename,filename) == 0){
        return invertedChainedIncrementOcurrence(node);
    }


    return invertedChainedListInsertNode(&((**node).next), filename);
}

int invertedChainedListGoThrough(invertedChainedList ** node){
    if((*node)==NULL){
        return 1;
    }

    printf("OCORRENCIAS - %d -- Documento - %s\n", (**node).ocurrences, (**node).filename);
    return invertedChainedListGoThrough(&((**node).next));
}
