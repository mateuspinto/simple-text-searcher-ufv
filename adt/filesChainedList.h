#ifndef FILESCHAINEDLIST_H
#define FILESCHAINEDLIST_H

typedef struct filesChainedList{
    FILE * file;
    struct filesChainedList * next;
} filesChainedList;

int filesChainedListStartList(filesChainedList ** node);
int filesChainedListCreateNode(filesChainedList ** node, char * filename);
int filesChainedListInsertFiles(filesChainedList ** node, char * dirname);


#endif
