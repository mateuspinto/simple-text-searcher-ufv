#include <stdio.h>
#include <stdlib.h>

#include "tst.h"
#include "characterBuffer.h"

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


int tst_node_auxgoThrough(tst_node ** node, characterBuffer ** buffer){

    characterBuffer * aux = NULL;

    if((**node).left != NULL)
        tst_node_auxgoThrough(&((**node).left), buffer);


    if((**node).endWord == 1){
        characterBuffer_buff(buffer, (**node).character);
            if((**node).center == NULL){
                while(characterBuffer_notEmpty(buffer))
                    printf("%c", characterBuffer_unbuff(buffer));
                    printf("\n");
                    characterBuffer_unbuff(buffer);

            } else {

                aux = *buffer;
                while(characterBuffer_notEmpty(&aux)){
                    //printf("CAIU AQUI -- \n");
                    printf("%c", characterBuffer_returnCharacter(&aux));
                    aux = aux->next;
                }
                printf("\n");
            }

    }



    if((**node).center != NULL){
        characterBuffer_buff(buffer, (**node).character);
        tst_node_auxgoThrough(&((**node).center), buffer);
    }

    if((**node).right != NULL)
        tst_node_auxgoThrough(&((**node).right), buffer);

    return 1;
}

int tst_node_goThrough(tst_node ** node){
    characterBuffer * buffer;

    characterBuffer_startBuffer(&buffer);
    return tst_node_auxgoThrough(node, &buffer);
}
