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
    if (strlen(word)<(**node).node.internal.position)
        return 0;
    
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

    if(*node == NULL){
        printf("ERRO DE MEMORIA\n");
        return 0;
    }

    (**node).nodeType = external;
    (**node).node.external.word = malloc(wordSize * sizeof(char));

    if((**node).node.external.word == NULL){
        printf("ERRO DE MEMORIA\n");
        return 0;
    }

    strcpy((**node).node.external.word, word);
    (**node).node.external.textList = NULL;
    invertedChainedListCreateNode(&((**node).node.external.textList), filename);

    return 1;
}

int patriciaNodeCreateInternalNode (patriciaNode ** node, char character, int position, patriciaNode ** left, patriciaNode ** right){
    (*node) = malloc(sizeof(patriciaNode));

    if((*node)==NULL){
        printf("ERRO DE MEMORIA\n");
        return 0;
    }
    (**node).nodeType = internal;
    (**node).node.internal.character = character;
    (**node).node.internal.position = position;
    (**node).node.internal.left = *left;
    (**node).node.internal.right = *right;

    return 1;
}

int patriciaNodeWhichIsDifferent(patriciaNode ** node, char * word){
    // Usa nó EXTERNO
    int position = 0;

    while((((**node).node.external.word)[position])==(word[position])){

        if((((**node).node.external.word)[position])=='\0' && (word[position])=='\0'){
            return -1;
        } //Trata palavras iguais

        position++;
    }


    return position;
}

int patriciaNodeReturnPosition(patriciaNode ** node){
    if((**node).nodeType == external)
        return 0;
    return ((**node)).node.internal.position;
}

char patriciaNodeReturnCharacter(patriciaNode ** node, int position){
    if((**node).nodeType == external)
        return (((**node).node.external.word)[position]);
    return ((**node)).node.internal.character;
}

int patriciaNodeInsertBetween(patriciaNode ** node, char * word, int position, char character, char * filename){
    patriciaNode * createdNode = NULL;
    patriciaNode * swap = *node;
    char internalNodeChar;

    if(patriciaNodeIsExternal(node)){ 
       
        patriciaNodeCreateExternalNode(&createdNode, word, filename);
        internalNodeChar =patriciaNodeReturnCharacter(node, position);

        if(word[position]>internalNodeChar){
            return patriciaNodeCreateInternalNode(node, word[position], position, &swap, &createdNode);
        } else {
            return patriciaNodeCreateInternalNode(node, internalNodeChar, position, &createdNode, &swap);
        }
    }

    if(position < (**node).node.internal.position){ 
       
        patriciaNodeCreateExternalNode(&createdNode, word, filename);
        internalNodeChar =patriciaNodeReturnCharacter(node, position);

        if(word[position]>=character){
            return patriciaNodeCreateInternalNode(node, character, position, &swap, &createdNode);
        } else {
            return patriciaNodeCreateInternalNode(node, character, position, &createdNode, &swap);
        }
    }

    if(position == (**node).node.internal.position && word[position]>patriciaNodeReturnCharacter(node, position)){ // MENOR OU MENOR E IGUAL??
       
        patriciaNodeCreateExternalNode(&createdNode, word, filename);
        internalNodeChar =patriciaNodeReturnCharacter(node, position);

        if(word[position]>internalNodeChar){
            return patriciaNodeCreateInternalNode(node, word[position], position, &swap, &createdNode);
        } else {
            return patriciaNodeCreateInternalNode(node, internalNodeChar, position, &createdNode, &swap);
        }
    }

    if(patriciaNodeCheckBitFlow(node, word)){
        return patriciaNodeInsertBetween(&((**node).node.internal.right),word, position, character, filename);
    } else {
        return patriciaNodeInsertBetween(&((**node).node.internal.left),word, position, character, filename);
    }
    
    return 0;
}

int patriciaNodeIncrementOcurrence(patriciaNode ** node, char * filename){
    if((**node).nodeType == internal){ // Problema Aqui
        return 0;
    }

    return invertedChainedListInsertNode(&((**node).node.external.textList), filename);
}

// patriciaNode ** patriciaNodeSearchWord(patriciaNode ** node, char * word){
//     patriciaNode ** aux = node;

//     if(*node == NULL)
//         return NULL;

//     while(!patriciaNodeIsExternal(aux)){
//         if(patriciaNodeCheckBitFlow(aux, word)){
//             aux = &((**aux).node.internal.right);
//         } else {
//             aux = &((**aux).node.internal.left);
//         }
//     }

//     if(patriciaNodeWhichIsDifferent(aux, word)==-1)
//         return aux;

//     return NULL;

// }

int patriciaNodeInsertWord (patriciaNode ** node, char * word, char * filename){
    int differPosition;
    patriciaNode ** aux = node;
    char character;

    if((*node) == NULL){
        return patriciaNodeCreateExternalNode(node, word, filename);
    }

    while(!patriciaNodeIsExternal(aux)){
        if (patriciaNodeCheckBitFlow(aux, word)){
            aux = &((**aux).node.internal.right);
        } else {
            aux = &((**aux).node.internal.left);
        }
    }

    differPosition = patriciaNodeWhichIsDifferent(aux, word);

    if(differPosition == -1){
        return patriciaNodeIncrementOcurrence(aux, filename);
    }

    if(word[differPosition]>((**aux).node.external.word)[differPosition]){
        character = word[differPosition];
    } else {
        character = ((**aux).node.external.word)[differPosition];
    } 

    return patriciaNodeInsertBetween(node, word, differPosition, character, filename);

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

int patriciaNodeGoThroughWithOcurrences(patriciaNode ** node){
    if((**node).nodeType == external){
        printf("%s - ", (**node).node.external.word);
        invertedChainedListGoThrough(&((**node).node.external.textList));
        printf("\n");
        return 1;
    }

    patriciaNodeGoThroughWithOcurrences(&((**node).node.internal.left));
    patriciaNodeGoThroughWithOcurrences(&((**node).node.internal.right));
    return 1;
}

invertedChainedList *patriciaNodeSearchWord(patriciaNode ** node, char *word){
    if(*node!=NULL){
        if((**node).nodeType==internal){
            if((**node).node.internal.character<=word[(**node).node.internal.position]){
               return patriciaNodeSearchWord(&(**node).node.internal.right, word);
            }else{
               return patriciaNodeSearchWord(&(**node).node.internal.left, word);
            }
        }else{
            if(!strcmp((**node).node.external.word, word)){
                return (**node).node.external.textList;
            }
        }
    }

    return NULL;
}
