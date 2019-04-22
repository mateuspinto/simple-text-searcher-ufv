/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#ifndef PATRICIANODE_H
#define PATRICIANODE_H

#include "invertedChainedList.h"

typedef enum {
  internal, external
} nodeType;

typedef struct patriciaNode {
    nodeType nodeType;
    union {
        struct{
            char character;
            int position;
            struct patriciaNode * left;
            struct patriciaNode * right;
        } internal;
        struct{
            char * word;
            invertedChainedList * textList;
        } external;
    } node;
} patriciaNode;

int patriciaNodeStartTree (patriciaNode ** node);
int patriciaNodeIsExternal (patriciaNode **node);
int patriciaNodeCheckBitFlow (patriciaNode **node, char * word);
int patriciaNodeCreateExternalNode (patriciaNode ** node, char * word, char * filename);
int patriciaNodeCreateInternalNode (patriciaNode ** node, char character, int position, patriciaNode ** left, patriciaNode ** right);
int patriciaNodeWhichIsDifferent(patriciaNode ** node, char * word);
int patriciaNodeReturnPosition(patriciaNode ** node);
char patriciaNodeReturnCharacter(patriciaNode ** node, int position);
int patriciaNodeInsertBetween(patriciaNode ** node, char * word, int position, char character, char * filename);
int patriciaNodeIncrementOcurrence(patriciaNode ** node, char * filename);
int patriciaNodeInsertWord (patriciaNode ** node, char * word, char * filename);
int patriciaNodeGoThrough(patriciaNode ** node);
int patriciaNodeGoThroughWithOcurrences(patriciaNode ** node);
invertedChainedList *patriciaNodeSearchWord(patriciaNode ** node, char *word);
int patriciaNodeDestroy(patriciaNode **node);


#endif
