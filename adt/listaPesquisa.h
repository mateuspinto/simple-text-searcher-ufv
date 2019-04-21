/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#ifndef LISTAPESQUISA_H
#define LISTAPESQUISA_H

typedef struct listaPesquisa{
    double wieght;
    char *filename;
    struct listaPesquisa *proximo;
}listaPesquisa;

int listaPesquisaInsereItem(listaPesquisa **ptr, double weight, char *filename);
int listaPesquisaDestroy(listaPesquisa **ptr);
int listaPesquisaShow(listaPesquisa **ptr);

#endif