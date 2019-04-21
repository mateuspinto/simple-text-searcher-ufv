/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#ifndef BSTNODE_H
#define BSTNODE_H

typedef struct bstNode
{
    double weight;
    char * filename;
    struct bstNode * left;
    struct bstNode * right;
} bstNode;


int bstNodeStartTree(bstNode ** node);
int bstNodeCreateNode(bstNode ** node, double weight, char * filename);
int bstNodeInsertFile(bstNode ** node, double weight, char * filename);
int bstNodeInOrder(bstNode ** node);
int bstNodeDestroy(bstNode ** node);

#endif