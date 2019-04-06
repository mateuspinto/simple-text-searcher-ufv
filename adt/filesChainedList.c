#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#include "filesChainedList.h"

int filesChainedListStartList(filesChainedList ** node){
    (*node) = NULL;

    #ifdef DEBUG
        printf("DEBUG == filesChainedList -- LISTA ENCADEADA CRIADA\n");
    #endif

    return 1;
}

int filesChainedListCreateNode(filesChainedList ** node, char * filename){
    (*node) = malloc(sizeof(filesChainedList));

    if((*node)==NULL){
        return 0;
    }

    (**node).next = NULL;
    (**node).file = fopen(filename, "r");
    printf("PONTEIRO PARA ARQUIVO -- %p\n", (**node).file);
}

int filesChainedListInsertFiles(filesChainedList ** node, char * dirname){
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
            filesChainedListCreateNode(node, filename);
            printf("%s\n", filename);
        }
    }

    closedir(dir);

    return 1;

}
