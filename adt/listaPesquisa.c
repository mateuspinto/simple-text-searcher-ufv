#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPesquisa.h"

int listaPesquisaInsereItem(listaPesquisa **ptr, double weight, char *filename){
    if(*ptr==NULL){
        *ptr=malloc(sizeof(listaPesquisa));
        (**ptr).wieght=weight;
        (**ptr).filename=filename;
        (**ptr).proximo=NULL;

        return 0;
    }else{
        if(!strcmp((**ptr).filename, filename)){
            (**ptr).wieght+=weight;

            return 1;
        }else{
            listaPesquisaInsereItem(&(**ptr).proximo, weight, filename);
        }
    }

    return 0;
}


int listaPesquisaDestroy(listaPesquisa **ptr){
    if(*ptr!=NULL){
        listaPesquisaDestroy(&(**ptr).proximo);
        free(*ptr);
        *ptr=NULL;
    }

    return 0;
}

int listaPesquisaShow(listaPesquisa **ptr){
    if(*ptr!=NULL){
        printf("Arquivo: %s | Peso: %lf\n", (**ptr).filename, (**ptr).wieght);
        listaPesquisaShow(&(**ptr).proximo);
    }

    return 0;
}