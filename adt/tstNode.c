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

#include "listAutoFill.h"
#include "tstNode.h"

#define MAXCHAR 45

int tstNodeStartTree(tstNode ** node){
    (*node) = NULL;
    return 1;
}

int tstNodeCreateNode(tstNode ** node, char character, short endWord){
    *node = malloc(sizeof(tstNode));

    if(*node == NULL) {
        printf("ERRO DE MEMORIA\n");
        return 0;
    }

    (**node).character = character;
    (**node).endWord = endWord;
    (**node).center = NULL;
    (**node).right = NULL;
    (**node).left = NULL;

    return 1;
}

int tstNodeSetEndWord(tstNode ** node, short endWord){
    (**node).endWord = endWord;

    return 1;
}

int tstNodeInsertWord(tstNode ** node, char * character){

    if(*node == NULL){
        
        if(character[1] == '\0'){

            return tstNodeCreateNode(node, *character, 1);

        } else {

        tstNodeCreateNode(node, *character, 0);

        return tstNodeInsertWord(&((**node).center), ++character);

        }
    }else{
        // printf("Letra %c %c\n", (**node).character, *character);
    }

    if(character[0]==(**node).character && character[1] == '\0'){ // Trata radicais ja presentes na arvore (exemplo: Mateus e depois Mat)

        return tstNodeSetEndWord(node, 1);
    }

     if((**node).character == *character) {

        return tstNodeInsertWord(&((**node).center), ++character);
    }

    if((**node).character < *character) {

        return tstNodeInsertWord(&((**node).right), character);
    }

    if((**node).character > *character) {

        return tstNodeInsertWord(&((**node).left), character);
}
    return 0;
}

int tstNodeSearchWord(tstNode ** node, char * character){

    if ((**node).character == * character){
        if ((**node).endWord == 1) {

            return 1;
        }

        return tstNodeSearchWord(&((**node).center), ++character);

    }

    if ((**node).character < * character && (**node).right != NULL){

        return tstNodeSearchWord(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        return tstNodeSearchWord(&((**node).left), character);
    }


    return 0;
}

tstNode ** tstNodeSearchRadical(tstNode ** node, char * character){

    if (*character == '\0'){

        return node;
    }

    if ((**node).character == * character){

        return tstNodeSearchRadical(&((**node).center), ++character);
    }

    if ((**node).character < * character && (**node).right != NULL){

        return tstNodeSearchRadical(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        return tstNodeSearchRadical(&((**node).left), character);
    }


    return 0;
}


int tstNodeAuxGoThrough(tstNode *atual, char * buffer, int h, listAutoFill **list)
{
    if (atual != NULL)
    {
        tstNodeAuxGoThrough(atual->left,buffer,h, list);

        buffer[h] = atual->character;
        if (atual->endWord)
        {
            buffer[h+1] = '\0';
            listAutoFillInsereItem(list, buffer);
        }

        tstNodeAuxGoThrough(atual->center,buffer,h + 1, list);

        tstNodeAuxGoThrough(atual->right,buffer,h, list);

        return 1;
    }

    return 0;
}

int tstNodeGoThrough(tstNode **raiz, listAutoFill **list)
{   
    if(raiz!=NULL){
        char buffer[MAXCHAR+2];
        return tstNodeAuxGoThrough(*raiz,buffer,0, list);
    }
    return 0;
}

int tstNodeIsNotInTree(tstNode ** node, char * character){

    if((*node) == NULL){
        return 1;
    }

    if ((**node).character == * character){
        if ((**node).endWord == 1) {

            return 0;
        }


        return tstNodeIsNotInTree(&((**node).center), ++character);

    }

    if ((**node).character < * character && (**node).right != NULL){

        return tstNodeIsNotInTree(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        return tstNodeIsNotInTree(&((**node).left), character);
    }


    return 1;
}

int tstNodeDestroy(tstNode ** node){
    if(*node!=NULL){
        tstNodeDestroy(&(**node).left);
        tstNodeDestroy(&(**node).center);
        tstNodeDestroy(&(**node).right);
        free(*node);
    }
    return 1;
}

tstNode** tstNodeSearch(tstNode **raiz, char *character){
    if(*raiz!=NULL && *character!='\0'){

        if((**raiz).character==*character){
            if((**raiz).endWord==1 && character[1]=='\0'){

                return raiz; 
            }else{
                return tstNodeSearch(&(**raiz).center, ++character);        
            }
        }
        else if((**raiz).character<*character){
            return tstNodeSearch(&(**raiz).right, character);      
            
        }else{
            return tstNodeSearch(&(**raiz).left, character);        
             
        }
    }

    return NULL;
}