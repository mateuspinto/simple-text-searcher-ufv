#include <stdio.h>
#include <stdlib.h>

#include "tst.h"

int tst_node_createNode(tst_node ** node, char character, short endWord){
    *node = malloc(sizeof(tst_node));

    if(*node == NULL)
        return 0;

    (**node).character = character;
    (**node).endWord = endWord;
    (**node).center = NULL;
    (**node).right = NULL;
    (**node).left = NULL;

    return 1;
}

int tst_node_setEndWord(tst_node ** node, short endWord){
    (**node).endWord = endWord;
    return 1;
}

int tst_node_insertWord(tst_node ** node, char * character){

    if(*node == NULL){
        if(*(character + sizeof(char)) == '\0'){
            tst_node_createNode(node, *character, 1);
            //printf("DEBUG == TST -%d- ULTIMO CARACTERE  - %c\n",  (**node).endWord, (**node).character);
            return 1;

        } else {

        tst_node_createNode(node, *character, 0);
        //printf("DEBUG == TST -%d- NÓ VAZIO -- CARACTERE  - %c\n",  (**node).endWord, (**node).character);
        tst_node_insertWord(&((**node).center), ++character);
        return 1;

        }
    }

    if(*(character + sizeof(char)) == '\0'){ // Trata radicais ja presentes na arvore (exemplo: Mateus e depois Mat)
        if ((**node).endWord == 0){
            tst_node_setEndWord(node, 1);
            //printf("DEBUG == TST -%d - NOVO FIM DE PALAVRA - %c\n", (**node).endWord, (**node).character);
        }
        return 1;
    }

     if((**node).character == *character) {
        //printf("DEBUG == TST --CARACTERE IGUAL - %c\n", *character);
        if (tst_node_insertWord(&((**node).center), ++character))
            return 1;
        return 0;
    }

    if((**node).character < *character) {
        //printf("DEBUG == TST --CARACTERE MAIOR - %c\n", *character);
        if (tst_node_insertWord(&((**node).right), character))
            return 1;
    return 0;
    }

    if((**node).character > *character) {
        //printf("DEBUG == TST --CARACTERE MENOR %c\n", *character);
        if (tst_node_insertWord(&((**node).left), character))
            return 1;
    return 0;
}

}

int tst_node_searchtWord(tst_node ** node, char * character){

    if ((**node).character == * character){
        if ((**node).endWord == 1) {
            return 1;
        }

        return tst_node_searchtWord(&((**node).center), ++character);
    }

    if ((**node).character < * character && (**node).right != NULL){
        return tst_node_searchtWord(&((**node).right), character);
    }

    if ((**node).character > * character && (**node).left != NULL){
        return tst_node_searchtWord(&((**node).left), character);
    }


    return 0;
}

int tst_node_goThrough(tst_node ** node){

    if((**node).left != NULL)
        tst_node_goThrough(&((**node).left));

    printf("%c", ((**node).character));
    if((**node).endWord == 1) printf("\n");

    if((**node).center != NULL)
        tst_node_goThrough(&((**node).center));

    if((**node).right != NULL)
        tst_node_goThrough(&((**node).right));
}
