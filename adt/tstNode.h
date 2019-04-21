/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#ifndef TST_H
#define TST_H

#include "listAutoFill.h"

typedef struct tstNode {
    char character;
    short endWord;
    struct tstNode * center;
    struct tstNode * right;
    struct tstNode * left;
} tstNode;


int tstNodeStartTree(tstNode ** node);
int tstNodeCreateNode(tstNode ** node, char character, short endWord);
int tstNodeSetEndWord(tstNode ** node, short endWord);
int tstNodeInsertWord(tstNode ** node, char * character);
int tstNodeSearchWord(tstNode ** node, char * character);
tstNode ** tstNodeSearchRadical(tstNode ** node, char * character);
int tstNodeAuxGoThrough(tstNode *atual, char * buffer, int h, listAutoFill **list);
int tstNodeGoThrough(tstNode **raiz, listAutoFill **list);
int tstNodeIsNotInTree(tstNode ** node, char * character);
int tstNodeDestroy(tstNode ** node);
tstNode** tstNodeSearch(tstNode **raiz, char *character);


#endif
