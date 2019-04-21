#ifndef INVERTEDCHAINEDLIST_H
#define INVERTEDCHAINEDLIST_H

typedef struct invertedChainedList {
    unsigned int ocurrences;
    char filename [30];
    struct invertedChainedList * next;
} invertedChainedList;

int invertedChainedListStartList(invertedChainedList **node);
int invertedChainedListCreateNode(invertedChainedList ** node, char * filename);
int invertedChainedIncrementOcurrence(invertedChainedList ** node);
int invertedChainedListInsertNode(invertedChainedList ** node, char * filename);
int invertedChainedListGoThrough(invertedChainedList ** node);
int invertedChainedListDestroy(invertedChainedList ** node);

#endif
