#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt/tstNode.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "adt/invertedChainedList.h"
#include "adt/listaPesquisa.h"
#include "adt/bstNode.h"

int generalFunctionsSetNumDifferentsWords(tstNode **arvoreAuxiliar, tstFileNode **tstFile, char *filename, char *word);
int generalFunctionsLoadWords(FILE * fp, char * filename, tstNode ** tstAutoFill, patriciaNode ** patricia, tstFileNode **tstFile);
int generalFunctionsAuxLoadTstFile(tstFileNode *tstFile, char * buffer, int h, tstNode ** tstAutoFill, patriciaNode ** patricia);
int generalFunctionsLoadTstFile(tstFileNode **tstFile, tstNode ** tstAutoFill, patriciaNode ** patricia);
int generalFunctionsSearch(tstFileNode **tstFile, patriciaNode ** patricia, char *words, int qtdFiles);
int generalFunctionsSearchWordAux(tstFileNode **tstFile, invertedChainedList **listFiles, listaPesquisa **listaTemp, int qtdFiles, int *qtdFilesAsWord);
int generalFunctionsLoadListInBST(listaPesquisa **listaPesquisaTemp, bstNode **bstPesquisa);
int generalFunctionsShowRadicalsAutoFill(tstNode **node, listAutoFill **list, char *word);
int generalFunctionsGetRadical(listAutoFill **list, char *word, char *string, int index);

#endif
