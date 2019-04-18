#ifndef TST_H
#define TST_H

typedef struct tstNode {
    char character;
    short endWord;
    struct tstNode * center;
    struct tstNode * right;
    struct tstNode * left;
} tstNode;


int tstNodeStartTree(tstNode ** node);
int tstNodeCreateNode(tstNode ** node, char character, short endWord);
int tstNodeSetEndWord(tstNode ** node, short endWord);
int tstNodeInsertWord(tstNode ** node, char * character);
int tstNodeSearchWord(tstNode ** node, char * character);
tstNode ** tstNodeSearchRadical(tstNode ** node, char * character);
int tstNodeAuxGoThrough(tstNode *atual, char * buffer, int h);
int tstNodeGoThrough(tstNode **raiz);
int tstNodeIsNotInTree(tstNode ** node, char * character);
int tstNodeDestroy(tstNode ** node);
tstNode** tstNodeSearch(tstNode **raiz, char *character);

#endif
