#ifndef PATRICIANODE_H
#define PATRICIANODE_H

#include "invertedChainedList.h"

typedef enum {
  internal, external
} nodeType;

typedef struct patriciaNode {
    nodeType nodeType;
    union {
        struct{
            char character;
            int position;
            struct patriciaNode * left;
            struct patriciaNode * right;
        } internal;
        struct{
            char * word;
            invertedChainedList * textList;
        } external;
    } node;
} patriciaNode;


#endif
