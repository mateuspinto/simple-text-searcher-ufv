/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#ifndef LISTAUTOFILL_H
#define LISTAUTOFILL_H

typedef struct listAutoFill{
    char *word;
    struct listAutoFill *next;
} listAutoFill;

int listAutoFillInsereItem(listAutoFill **list, char *palavra);
int listAutoFillShowItens(listAutoFill **list, char *word);
int listAutoFillShowItensAux(listAutoFill **list, int *count, char *word);
listAutoFill *listAutoFillGetItem(listAutoFill **list, int index);
int listaAutoFillDestroy(listAutoFill **list);


#endif