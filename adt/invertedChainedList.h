/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM
ARVORES DIGITAIS Professora: Doutora Glaucia Braga e Silva Integrantes
(Matricula - Nome): 1278 - Angelo Bernar Tessaro Morelo 3513 - Leandro Lazaro
Araujo Vieira 3489 - Mateus Pinto da Silva
*/

#ifndef INVERTEDCHAINEDLIST_H
#define INVERTEDCHAINEDLIST_H

typedef struct invertedChainedList {
  unsigned int ocurrences;
  char filename[30];
  struct invertedChainedList *next;
} invertedChainedList;

int invertedChainedListStartList(invertedChainedList **node);
int invertedChainedListCreateNode(invertedChainedList **node, char *filename);
int invertedChainedIncrementOcurrence(invertedChainedList **node);
int invertedChainedListInsertNode(invertedChainedList **node, char *filename);
int invertedChainedListGoThrough(invertedChainedList **node);
int invertedChainedListDestroy(invertedChainedList **node);

#endif
