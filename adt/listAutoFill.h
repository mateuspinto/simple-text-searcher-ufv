#ifndef LISTAUTOFILL_H
#define LISTAUTOFILL_H

typedef struct listAutoFill{
    char *word;
    struct lisAutoFill *next;
}listAutoFill;

int listAutoFillInsereItem(listAutoFill **list, char *palavra);
int listAutoFillShowItens(listAutoFill **list, char *word);
int listAutoFillShowItensAux(listAutoFill **list, int *count, char *word);
listAutoFill *listAutoFillGetItem(listAutoFill **list, int index);
int listaAutoFillDestroy(listAutoFill **list);


#endif