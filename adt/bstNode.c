#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstNode.h"

int bstNodeStartTree(bstNode ** node){
    (*node) = NULL;
    return 1;
}

int bstNodeCreateNode(bstNode ** node, int weight, char * filename){
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

int bstNodeInsertFile(bstNode ** node, int weight, char * filename){

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
    printf("%d - %s\n", (**node).weight, (**node).filename);
    bstNodeInOrder(&((**node).right));

    return 0;
}