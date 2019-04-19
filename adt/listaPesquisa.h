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