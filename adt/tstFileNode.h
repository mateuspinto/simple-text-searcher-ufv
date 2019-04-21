/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#ifndef TSTFILENODE_H
#define TSTFILENODE_H

typedef struct tstFileNode {
    char character;
    FILE * file;
    int numDifferentsWords;
    struct tstFileNode * center;
    struct tstFileNode * right;
    struct tstFileNode * left;
} tstFileNode;

int tstFileNodeStartTree(tstFileNode ** node);
int tstFileNodeCreateNode(tstFileNode ** node, char character, char * filename);
int tstFileNodeAuxInsertFile(tstFileNode ** node, char * character, char * filename);
int tstFileNodeInsertInputs(tstFileNode ** node, char * dirname, int *qtdFiles);
int tstFileNodeAuxGoThrough(tstFileNode *atual, char * buffer, int h);
int tstFileNodeGoThrough(tstFileNode **raiz);
tstFileNode** tstFileNodeSearch(tstFileNode **raiz, char *character);
int tstFileNodeDestroy(tstFileNode **node);


#endif
