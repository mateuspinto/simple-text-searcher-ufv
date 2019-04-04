typedef struct tst_node {
    char character;
    short endWord;
    struct tst_node * center;
    struct tst_node * right;
    struct tst_node * left;
} tst_node;

int tst_node_createNode(tst_node ** node, char character, short endWord);
int tst_node_setEndWord(tst_node ** node, short endWord);
int tst_node_insertWord(tst_node ** node, char * character);
