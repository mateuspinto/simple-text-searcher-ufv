#ifndef BSTNODE_H
#define BSTNODE_H

typedef struct bstNode
{
    int weight;
    char * filename;
    struct bstNode * left;
    struct bstNode * right;
} bstNode;


int bstNodeStartTree(bstNode ** node);
int bstNodeCreateNode(bstNode ** node, int weight, char * filename);
int bstNodeInsertFile(bstNode ** node, int weight, char * filename);
int bstNodeInOrder(bstNode ** node);
int bstNodeDestroy(bstNode ** node);

#endif