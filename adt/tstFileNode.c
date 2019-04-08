#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#include "tstFileNode.h"
#include "../generalFunctions.h"

int tstFileNodeStartTree(tstFileNode ** node){
    (*node) = NULL;
    return 1;
}

int tstFileNodeCreateNode(tstFileNode ** node, char character, char * filename){
    *node = malloc(sizeof(tstFileNode));

    if(*node == NULL) {

        #ifdef DEBUG
            printf("DEBUG == TST -- NO NAO CRIADO  - ERRO DE MEMORIA\n");
        #endif


        return 0;
    }

    (**node).character = character;
    (**node).file = fopen(filename, "r");
    (**node).center = NULL;
    (**node).right = NULL;
    (**node).left = NULL;

    #ifdef DEBUG
        printf("DEBUG == TST -%p- NO CRIADO  - %c\n",  (**node).file, (**node).character);
    #endif

    return 1;

}

int tstFileNodeAuxInsertFile(tstFileNode ** node, char * character, char * filename){
    if(*node == NULL){
        if(*(character + sizeof(char)) == '\0'){
            tstFileNodeCreateNode(node, *character, filename);

            #ifdef DEBUG
                printf("DEBUG == TST -%p- ULTIMO CARACTERE  - %c\n",  (**node).file, (**node).character);
            #endif

            return 1;

        } else {

        tstFileNodeCreateNode(node, *character, NULL);

        #ifdef DEBUG
            printf("DEBUG == TST -%p- NÓ VAZIO -- CARACTERE  - %c\n",  (**node).file, (**node).character);
        #endif

        tstFileNodeAuxInsertFile(&((**node).center), ++character, filename);
        return 1;

        }
    }

    /* if(*(character + sizeof(char)) == '\0'){ // Trata radicais ja presentes na arvore (exemplo: Mateus e depois Mat)
        if ((**node).endWord == 0){
            tstNodeSetEndWord(node, 1);

            #ifdef DEBUG
                printf("DEBUG == TST -%d - NOVO FIM DE PALAVRA - %c\n", (**node).endWord, (**node).character);
            #endif

        }
        return 1;
    } */

     if((**node).character == *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE IGUAL - %c\n", *character);
        #endif

        if (tstFileNodeAuxInsertFile(&((**node).center), ++character, filename))
            return 1;
        return 0;
    }

    if((**node).character < *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE MAIOR - %c\n", *character);
        #endif

        if (tstFileNodeAuxInsertFile(&((**node).right), character, filename))
            return 1;
    return 0;
    }

    if((**node).character > *character) {

        #ifdef DEBUG
            printf("DEBUG == TST --CARACTERE MENOR %c\n", *character);
        #endif

        if (tstFileNodeAuxInsertFile(&((**node).left), character, filename))
            return 1;
    return 0;
}
    return 0;
}

int tstFileNodeInsertFile(tstFileNode ** node, char * filename){
    char swap[PATH_MAX];
    char * nameForTree;

    strcpy(swap, filename);
    strtok(swap, "/");
    nameForTree = strtok(NULL, "/");

    return tstFileNodeAuxInsertFile(node, nameForTree, filename);
}

int tstFileNodeInsertInputs(tstFileNode ** node, char * dirname){
    char cwd[PATH_MAX];
    char filename[PATH_MAX];
    DIR *dir;
    struct dirent *lsdir;

    getcwd(cwd, sizeof(cwd));
    strcat(cwd, "/");
    strcat(cwd, dirname);

    dir = opendir(cwd);

    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        if((strcmp(lsdir->d_name, "..")!=0) && strcmp(lsdir->d_name, ".")!=0){
            strcpy(filename, dirname);
            strcat(filename, "/");
            strcat(filename, lsdir->d_name);
            tstFileNodeInsertFile(node, filename);
            //printf("%s\n", filename);
        }
    }

    closedir(dir);

    return 1;
}

int tstFileNodeAuxGoThrough(tstFileNode *atual, char * buffer, int h)
{
    if (atual != NULL)
    {
        tstFileNodeAuxGoThrough(atual->left,buffer,h);

        buffer[h] = atual->character;
        if ((atual->file)!=NULL)
        {
            buffer[h+1] = ']';
            buffer[h+2] = '\0';
            printf("%s\n",buffer);
        }

        tstFileNodeAuxGoThrough(atual->center,buffer,h + 1);

        tstFileNodeAuxGoThrough(atual->right,buffer,h);

        return 1;
    }

    return 0;
}

int tstFileNodeGoThrough(tstFileNode **raiz)
{
    char buffer[PATH_MAX+2] = "[";
    return tstFileNodeAuxGoThrough(*raiz,buffer,1);
}
