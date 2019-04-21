#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listAutoFill.h"

int listAutoFillInsereItem(listAutoFill **list, char *palavra){
    if((*list)==NULL){
        char *temp=malloc(50*sizeof(char));
        strcpy(temp, palavra);
        (*list)=malloc(sizeof(listAutoFill));
        (**list).word=temp;
        (**list).next=NULL;
    }else{
        listAutoFillInsereItem(&(**list).next, palavra);
    }
    return 0;
}

int listAutoFillShowItens(listAutoFill **list, char *word){
    printf("0 - %s\n",word);
    int *count=malloc(sizeof(int));
    (*count)=0;
    listAutoFillShowItensAux(list, count, word);
}

int listAutoFillShowItensAux(listAutoFill **list, int *count, char *word){

    if((*list)!=NULL){
        char temp[10];
        strcpy(temp, word);
        strcat(temp, (**list).word);
        (*count)+=1;
        printf("%d - %s\n",*count, temp);
        listAutoFillShowItensAux(&(**list).next, count, word);
    }

    return 0;
}
listAutoFill *listAutoFillGetItem(listAutoFill **list, int index){
    if((*list)!=NULL){
        index-=1;
        if(index==0){
            return (*list);
        }else{
            return listAutoFillGetItem(&(**list).next, index);
        }
    }

    return NULL;
}

int listaAutoFillDestroy(listAutoFill **list){
    if((*list)!=NULL){
        listaAutoFillDestroy(&(**list).next);
        free((*list));
        (*list)=NULL;
    }

    return 0;
}
