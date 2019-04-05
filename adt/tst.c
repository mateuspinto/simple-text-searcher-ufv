#include <stdio.h>
#include <stdlib.h>

#include "tst.h"

#define MAXCHAR 45

int tst_node_createNode(tst_node ** node, char character, short endWord){
    *node = malloc(sizeof(tst_node));

    if(*node == NULL) {

        #ifdef DEBUG
            printf("DEBUG == TST -- NO NAO CRIADO  - ERRO DE MEMORIA\n");
        #endif


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

int tst_node_setEndWord(tst_node ** node, short endWord){
    (**node).endWord = endWord;

    #ifdef DEBUG
        printf("DEBUG == TST -- ENDWORD SETADO PARA  - %d\n",  (**node).endWord);
    #endif


    return 1;
}

int tst_node_insertWord(tst_node ** node, char * character){

    if(*node == NULL){
        if(*(character + sizeof(char)) == '\0'){
            tst_node_createNode(node, *character, 1);

            #ifdef DEBUG
                printf("DEBUG == TST -%d- ULTIMO CARACTERE  - %c\n",  (**node).endWord, (**node).character);
            #endif

            return 1;

        } else {

        tst_node_createNode(node, *character, 0);

        #ifdef DEBUG
            printf("DEBUG == TST -%d- NÓ VAZIO -- CARACTERE  - %c\n",  (**node).endWord, (**node).character);
        #endif

        tst_node_insertWord(&((**node).center), ++character);
        return 1;

        }
    }

    if(*(character + sizeof(char)) == '\0'){ // Trata radicais ja presentes na arvore (exemplo: Mateus e depois Mat)
        if ((**node).endWord == 0){
            tst_node_setEndWord(node, 1);

            #ifdef DEBUG
                printf("DEBUG == TST -%d - NOVO FIM DE PALAVRA - %c\n", (**node).endWord, (**node).character);
            #endif

        }
        return 1;
    }

     if((**node).character == *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE IGUAL - %c\n", *character);
        #endif

        if (tst_node_insertWord(&((**node).center), ++character))
            return 1;
        return 0;
    }

    if((**node).character < *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE MAIOR - %c\n", *character);
        #endif

        if (tst_node_insertWord(&((**node).right), character))
            return 1;
    return 0;
    }

    if((**node).character > *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE MENOR %c\n", *character);
        #endif

        if (tst_node_insertWord(&((**node).left), character))
            return 1;
    return 0;
}
    return 0;
}

int tst_node_searchtWord(tst_node ** node, char * character){

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

        return tst_node_searchtWord(&((**node).center), ++character);

    }

    if ((**node).character < * character && (**node).right != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA MAIOR, INDO PARA A DIREITA %c\n", *character);
        #endif

        return tst_node_searchtWord(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO PALAVRA -- LETRA MENOR, INDO PARA A ESQUERDA %c\n", *character);
        #endif

        return tst_node_searchtWord(&((**node).left), character);
    }


    return 0;
}

tst_node ** tst_node_searchtRadical(tst_node ** node, char * character){

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

        return tst_node_searchtRadical(&((**node).center), ++character);
    }

    if ((**node).character < * character && (**node).right != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO RADICAL -- LETRA MAIOR, INDO PARA DIREITA %c\n", *character);
        #endif

        return tst_node_searchtRadical(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){

        #ifdef DEBUG
            printf("DEBUG == TST -- PROCURANDO RADICAL -- LETRA MENOR, INDO PARA ESQUERDA %c\n", *character);
        #endif


        return tst_node_searchtRadical(&((**node).left), character);
    }


    return 0;
}


int tst_node_aux_goThrough(tst_node *atual, char * buffer, int h)
{
    if (atual != NULL)
    {
        tst_node_aux_goThrough(atual->left,buffer,h);

        buffer[h] = atual->character;
        if (atual->endWord)
        {
            buffer[h+1] = ']';
            buffer[h+2] = '\0';
            printf("%s\n",buffer);
        }

        tst_node_aux_goThrough(atual->center,buffer,h + 1);

        tst_node_aux_goThrough(atual->right,buffer,h);

        return 1;
    }

    return 0;
}

int tst_node_goThrough(tst_node *raiz)
{
    char buffer[MAXCHAR+2] = "[";
    return tst_node_aux_goThrough(raiz,buffer,1);
}
