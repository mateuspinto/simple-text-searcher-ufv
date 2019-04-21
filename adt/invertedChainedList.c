/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "invertedChainedList.h"

int invertedChainedListStartList(invertedChainedList **node){
    (*node) = NULL;

    return 1;
}

int invertedChainedListCreateNode(invertedChainedList ** node, char * filename){

    (*node) = malloc(sizeof(invertedChainedList));

    if((*node)==NULL){
        printf("ERRO DE MEMORIA\n");
        return 0;
    }

    (**node).ocurrences = 1;

    strcpy((**node).filename, filename);
    
    (**node).next = NULL;

    return 1;
}

int invertedChainedIncrementOcurrence(invertedChainedList ** node){
    (**node).ocurrences++;

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
        printf("<%d/%s>", (**node).ocurrences, (**node).filename);
        return 1;
    }

    printf("<%d/%s>, ", (**node).ocurrences, (**node).filename);
    return invertedChainedListGoThrough(&((**node).next));
}

int invertedChainedListDestroy(invertedChainedList ** node){
    if(*node!=NULL){
        invertedChainedListDestroy(&(**node).next);
        free(*node);
        (*node)=NULL;
    }
    return 0;
}
