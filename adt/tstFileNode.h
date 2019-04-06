#ifndef TSTFILENODE_H
#define TSTFILENODE_H

typedef struct tstFileNode {
    char character;
    FILE * file;
    struct tstFileNode * center;
    struct tstFileNode * right;
    struct tstFileNode * left;
} tstFileNode;

int tstFileNodeStartTree(tstFileNode ** node);
int tstFileNodeCreateNode(tstFileNode ** node, char character, char * filename);
int tstFileNodeAuxInsertFile(tstFileNode ** node, char * character, char * filename);
int tstFileNodeInsertInputs(tstFileNode ** node, char * dirname);

#endif
