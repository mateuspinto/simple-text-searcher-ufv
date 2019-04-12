#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "invertedChainedList.h"

int invertedChainedListStartList(invertedChainedList **node){
    (*node) = NULL;

    #ifdef DEBUG
        printf("DEBUG == invertedChainedList -- LISTA ENCADEADA CRIADA\n");
    #endif

    printf("LISTA CRIADA\n");

    return 1;
}

int invertedChainedListCreateNode(invertedChainedList ** node, char * filename){

    (*node) = malloc(sizeof(invertedChainedList));

    if((*node)==NULL){
        printf("ERRO DE MEMORIA\n");
        return 0;
    }


    (**node).next = NULL;
    (**node).ocurrences = 1;

    strcpy((**node).filename, filename);

    #ifdef DEBUG
        printf("DEBUG == invertedChainedList -- CELULA CRIADA -- TEXTO = %s -- OCORRENCIAS = %d\n",(**node).filename, (**node).ocurrences);
    #endif

    return 1;
}

int invertedChainedIncrementOcurrence(invertedChainedList ** node){
    (** node).ocurrences++;

    #ifdef DEBUG
        printf("DEBUG == invertedChainedList -- CELULA INCREMENTADA -- TEXTO = %s -- OCORRENCIAS = %d\n",(**node).filename, (**node).ocurrences);
    #endif


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

    if(((**node).next)==NULL){
        printf("(%d/%s)", (**node).ocurrences, (**node).filename);
        return 1;
    }

    printf("(%d/%s), ", (**node).ocurrences, (**node).filename);
    return invertedChainedListGoThrough(&((**node).next));
}
