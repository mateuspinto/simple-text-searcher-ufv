#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patriciaNode.h"
#include "invertedChainedList.h"

int patriciaNodeStartTree (patriciaNode ** node){
    (*node) = NULL;
    return 1;
}

int patriciaNodeIsExternal (patriciaNode **node){
    if((**node).nodeType == external){
        return 1;
    }
    return 0;
}

int patriciaNodeCheckBitEquals (patriciaNode **node, char * word){
    // Usa nó INTERNO
    if((**node).node.internal.character -= word[(**node).node.internal.position])
    return 1;

    return 0;
}

int patriciaNodeCheckBitFlow (patriciaNode **node, char * word){
    // Usa nó INTERNO
    if(word[(**node).node.internal.position] >= (**node).node.internal.character){
        return 1;
    }

    return 0;
}

int patriciaNodeCreateExternalNode (patriciaNode ** node, char * word, char * filename){
    int wordSize = 1;

    while((word[wordSize])!='\0'){
        wordSize++;
    }

    (*node) = malloc(sizeof(patriciaNode));
    (**node).nodeType = external;
    (**node).node.external.word = malloc(wordSize * sizeof(char));
    strcpy((**node).node.external.word, word);
    (**node).node.external.textList = NULL;
    invertedChainedListInsertNode(&((**node).node.external.textList), filename);

    //printf("NÓ EXTERNO CRIADO -- %s\n", (**node).node.external.word);

    return 1;
}

int patriciaNodeCreateInternalNode (patriciaNode ** node, char character, int position, patriciaNode ** left, patriciaNode ** right){
    (*node) = malloc(sizeof(patriciaNode));
    if((*node)==NULL){
        return 0;
    }
    (**node).nodeType = internal;
    (**node).node.internal.character = character;
    (**node).node.internal.position = position;
    (**node).node.internal.left = *left;
    (**node).node.internal.right = *right;

    //printf("NÓ INTERNO CRIADO - direita // posicao - %d // caractere - %c\n", (**node).node.internal.position, (**node).node.internal.character);

    return 1;
}

int patriciaNodeWhichIsDifferent(patriciaNode ** node, char * word){
    // Usa nó EXTERNO
    int position = 0;

    while((((**node).node.external.word)[position])==(word[position])){
        //printf("BIGO %c %c\n", (**node).node.external.word[position], word[position]);

        if((((**node).node.external.word)[position])=='\0' && (word[position])=='\0'){
            //printf("CAIU NO RETURN \n");
            return -1;
        } //Trata palavras iguais

        if((((**node).node.external.word)[position])=='\0' || word[position]=='\0'){
            return position;
        } //Trata palavras de tamanhos diferentes

        position++;
    }


    return position;
}

char patriciaNodeReturnCharacter(patriciaNode ** node, int position){
    if((**node).nodeType == external)
    return (((**node).node.external.word)[position]);
    return ((**node)).node.internal.character;
}

int patriciaNodeInsertBetween(patriciaNode ** node, char * word, int position, char * filename){
    patriciaNode * createdNode = NULL;
    patriciaNode * swap = *node;
    char internalNodeChar;
    //printf("Insert between chamado para %s\n", word);
    if(patriciaNodeIsExternal(node)){
        //printf("NÓ EXTERNO DETECTADO, DESTROÇANDO..\n");
        patriciaNodeCreateExternalNode(&createdNode, word, filename);
        internalNodeChar =patriciaNodeReturnCharacter(node, position);
        //printf("PALAVRA INSERIDA - (%c) // PALAVRA DO NÓ - (%c)\n", word[position], internalNodeChar);
        if(word[position]>internalNodeChar){
            //printf("LETRA INSERIDA MAIOR\n");
            return patriciaNodeCreateInternalNode(node, word[position], position, &swap, &createdNode);
        } else {
            //printf("LETRA INSERIDA MENOR\n");
            return patriciaNodeCreateInternalNode(node, internalNodeChar, position, &createdNode, &swap);
        }
    } else if(position < (**node).node.internal.position){ // MENOR OU MENOR E IGUAL??
        patriciaNodeCreateExternalNode(&createdNode, word, filename);
        internalNodeChar =patriciaNodeReturnCharacter(node, position);
        if(word[position]>internalNodeChar){
            return patriciaNodeCreateInternalNode(node, word[position], position, &swap, &createdNode);
        } else {
            return patriciaNodeCreateInternalNode(node, internalNodeChar, position, &createdNode, &swap);
        }
    }else{
        if(patriciaNodeCheckBitFlow(node, word)){
            return patriciaNodeInsertBetween(&((**node).node.internal.right),word, position, filename);
        } else {
            return patriciaNodeInsertBetween(&((**node).node.internal.left),word, position, filename);
        }
    }
    return 0;
}

int patriciaNodeInsertWord (patriciaNode ** node, char * word, char * filename){
    int differPosition;
    patriciaNode ** aux = node;

    if((*node) == NULL){
        return patriciaNodeCreateExternalNode(node, word, filename);
    }

    while(!patriciaNodeIsExternal(aux)){
        if (patriciaNodeCheckBitFlow(aux, word)){
            //printf("Passaando por nó interno - Foi para a direita // posicao - %d // caractere - %c\n", (**node).node.internal.position, (**node).node.internal.character);
            aux = &((**aux).node.internal.right);
        } else {
            //printf("Passaando por nó interno - Foi para a esquerda // posicao - %d // caractere - %c\n", (**node).node.internal.position, (**node).node.internal.character);
            aux = &((**aux).node.internal.left);
        }
    }

    //printf("%s - AA\n", (**node).node.external.word);


    differPosition = patriciaNodeWhichIsDifferent(aux, word);

    if(differPosition == -1){
        //invertedChainedListInsertNode(&((**node).node.external.textList), filename);
        return 0;
    }

    //printf("O BIT %d É DIFERENTE\n", differPosition);

    return patriciaNodeInsertBetween(node, word, differPosition, filename);

}

int patriciaNodeGoThrough(patriciaNode ** node){
    if((**node).nodeType == external){
        printf("%s\n", (**node).node.external.word);
        return 1;
    }

    patriciaNodeGoThrough(&((**node).node.internal.left));
    patriciaNodeGoThrough(&((**node).node.internal.right));
    return 1;
}
