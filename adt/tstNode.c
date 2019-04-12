#include <stdio.h>
#include <stdlib.h>

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

    #ifdef DEBUG
        printf("DEBUG == TST -%d- NO CRIADO  - %c\n",  (**node).endWord, (**node).character);
    #endif

    return 1;
}

int tstNodeSetEndWord(tstNode ** node, short endWord){
    (**node).endWord = endWord;

    #ifdef DEBUG
        printf("DEBUG == TST -- ENDWORD SETADO PARA  - %d\n",  (**node).endWord);
    #endif


    return 1;
}

int tstNodeInsertWord(tstNode ** node, char * character){

    if(*node == NULL){
        if(*(character + sizeof(char)) == '\0'){
            tstNodeCreateNode(node, *character, 1);

            #ifdef DEBUG
                printf("DEBUG == TST -%d- ULTIMO CARACTERE  - %c\n",  (**node).endWord, (**node).character);
            #endif

            return 1;

        } else {

        tstNodeCreateNode(node, *character, 0);

        #ifdef DEBUG
            printf("DEBUG == TST -%d- NÓ VAZIO -- CARACTERE  - %c\n",  (**node).endWord, (**node).character);
        #endif

        tstNodeInsertWord(&((**node).center), ++character);
        return 1;

        }
    }

    if(character[1] == '\0'){ // Trata radicais ja presentes na arvore (exemplo: Mateus e depois Mat)
            (**node).endWord = 1;

            #ifdef DEBUG
                printf("DEBUG == TST -%d - NOVO FIM DE PALAVRA - %c\n", (**node).endWord, (**node).character);
            #endif

        return 1;
    }

     if((**node).character == *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE IGUAL - %c\n", *character);
        #endif

        if (tstNodeInsertWord(&((**node).center), ++character))
            return 1;
        return 0;
    }

    if((**node).character < *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE MAIOR - %c\n", *character);
        #endif

        if (tstNodeInsertWord(&((**node).right), character))
            return 1;
    return 0;
    }

    if((**node).character > *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE MENOR %c\n", *character);
        #endif

        if (tstNodeInsertWord(&((**node).left), character))
            return 1;
    return 0;
}
    return 0;
}

int tstNodeSearchWord(tstNode ** node, char * character){

    if ((**node).character == * character){
        if ((**node).endWord == 1) {

            #ifdef DEBUG
                printf("DEBUG == TST -- PROCURANDO PALAVRA -- PALAVRA ENCONTRADA %c\n", *character);
            #endif

            return 1;
        }

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA ENCONTRADA, DESCENDO %c\n", *character);
        #endif

        return tstNodeSearchWord(&((**node).center), ++character);

    }

    if ((**node).character < * character && (**node).right != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA MAIOR, INDO PARA A DIREITA %c\n", *character);
        #endif

        return tstNodeSearchWord(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA MENOR, INDO PARA A ESQUERDA %c\n", *character);
        #endif

        return tstNodeSearchWord(&((**node).left), character);
    }


    return 0;
}

tstNode ** tstNodeSearchRadical(tstNode ** node, char * character){

    if (*character == '\0'){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO RADICAL -- FIM DO RADICAL EM %p\n", node);
        #endif

        return node;
    }

    if ((**node).character == * character){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO RADICAL -- LETRA ENCONTRADA, INDO PARA BAIXO %c\n", *character);
        #endif

        return tstNodeSearchRadical(&((**node).center), ++character);
    }

    if ((**node).character < * character && (**node).right != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO RADICAL -- LETRA MAIOR, INDO PARA DIREITA %c\n", *character);
        #endif

        return tstNodeSearchRadical(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO RADICAL -- LETRA MENOR, INDO PARA ESQUERDA %c\n", *character);
        #endif


        return tstNodeSearchRadical(&((**node).left), character);
    }


    return 0;
}


int tstNodeAuxGoThrough(tstNode *atual, char * buffer, int h)
{
    if (atual != NULL)
    {
        tstNodeAuxGoThrough(atual->left,buffer,h);

        buffer[h] = atual->character;
        if (atual->endWord)
        {
            buffer[h+1] = ']';
            buffer[h+2] = '\0';
            printf("%s\n",buffer);
        }

        tstNodeAuxGoThrough(atual->center,buffer,h + 1);

        tstNodeAuxGoThrough(atual->right,buffer,h);

        return 1;
    }

    return 0;
}

int tstNodeGoThrough(tstNode **raiz)
{
    char buffer[MAXCHAR+2] = "[";
    return tstNodeAuxGoThrough(*raiz,buffer,1);
}

int tstNodeIsNotInTree(tstNode ** node, char * character){

    if((*node) == NULL){
        return 1;
    }

    if ((**node).character == * character){
        if ((**node).endWord == 1) {

            #ifdef DEBUG
                printf("DEBUG == TST -- PROCURANDO PALAVRA -- PALAVRA ENCONTRADA - %c - %c\n", *character, (**node).character);
            #endif

            return 0;
        }

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA ENCONTRADA, DESCENDO - %c - %c -- É O FIM DA PALAVRA? - %d\n", *character, (**node).character, (**node).endWord);
        #endif

        return tstNodeIsNotInTree(&((**node).center), ++character);

    }

    if ((**node).character < * character && (**node).right != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA MAIOR, INDO PARA A DIREITA - %c - %c\n", *character, (**node).character);
        #endif

        return tstNodeIsNotInTree(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA MENOR, INDO PARA A ESQUERDA - %c - %c\n", *character, (**node).character);
        #endif

        return tstNodeIsNotInTree(&((**node).left), character);
    }


    return 1;
}
