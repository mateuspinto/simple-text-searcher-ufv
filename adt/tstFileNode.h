/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM
ARVORES DIGITAIS Professora: Doutora Glaucia Braga e Silva Integrantes
(Matricula - Nome): 1278 - Angelo Bernar Tessaro Morelo 3513 - Leandro Lazaro
Araujo Vieira 3489 - Mateus Pinto da Silva
*/

#ifndef TSTFILENODE_H
#define TSTFILENODE_H

#include <stdio.h>

typedef struct tstFileNode {
  char character;
  FILE *file;
  int numDifferentsWords;
  struct tstFileNode *center;
  struct tstFileNode *right;
  struct tstFileNode *left;
} tstFileNode;

int tstFileNodeStartTree(tstFileNode **node);
int tstFileNodeCreateNode(tstFileNode **node, char character, char *filename);
int tstFileNodeAuxInsertFile(tstFileNode **node, char *character,
                             char *filename);
int tstFileNodeInsertFile(tstFileNode **node, char *filename);
int tstFileNodeInsertInputs(tstFileNode **node, char *dirname, int *qtdFiles);
tstFileNode **tstFileNodeSearch(tstFileNode **raiz, char *character);
int tstFileNodeDestroy(tstFileNode **node);

#endif
