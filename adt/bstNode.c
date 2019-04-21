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
#include "bstNode.h"

int bstNodeStartTree(bstNode ** node){
    (*node) = NULL;
    return 1;
}

int bstNodeCreateNode(bstNode ** node, double weight, char * filename){
    (*node) = malloc(sizeof(bstNode));

    if(*node==NULL){
        printf("ERRO DE MEMORIA\n");
        return 0;
    }

    (**node).weight = weight;
    (**node).left = NULL;
    (**node).right = NULL;
    (**node).filename = malloc(strlen(filename) * sizeof(char));
    strcpy((**node).filename, filename);

    return 1;
}

int bstNodeInsertFile(bstNode ** node, double weight, char * filename){

    if(*node == NULL)
        return bstNodeCreateNode(node, weight, filename);

    if((**node).weight == weight && (strcmp((**node).filename, filename) == 0))
        return 0;
    

    if(((**node).weight == weight && (strcmp((**node).filename, filename) > 0)) || ((**node).weight < weight))
        return bstNodeInsertFile(&((**node).left), weight, filename);
    

    if(((**node).weight == weight && (strcmp((**node).filename, filename) < 0)) || (**node).weight > weight)
        return bstNodeInsertFile(&((**node).right), weight, filename);
    
    return 1;
    
}

int bstNodeInOrder(bstNode ** node){

    if((*node)==NULL)
        return 1;

    bstNodeInOrder(&((**node).left));
    printf("%lf - %s\n", (**node).weight, (**node).filename);
    bstNodeInOrder(&((**node).right));

    return 0;
}

int bstNodeDestroy(bstNode ** node){
    
    if(*node!=NULL){
        bstNodeDestroy(&(**node).left);
        bstNodeDestroy(&(**node).right);
        free((**node).filename);
        (**node).filename = NULL;
        free(*node);
        (*node) = NULL;
    }
    return 0;
}