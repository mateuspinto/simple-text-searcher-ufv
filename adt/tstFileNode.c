/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM
ARVORES DIGITAIS Professora: Doutora Glaucia Braga e Silva Integrantes
(Matricula - Nome): 1278 - Angelo Bernar Tessaro Morelo 3513 - Leandro Lazaro
Araujo Vieira 3489 - Mateus Pinto da Silva
*/

#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../generalFunctions.h"
#include "tstFileNode.h"

int tstFileNodeStartTree(tstFileNode **node) {
  (*node) = NULL;
  return 1;
}

int tstFileNodeCreateNode(tstFileNode **node, char character, char *filename) {
  *node = malloc(sizeof(tstFileNode));

  if (*node == NULL) {
    printf("ERRO DE MEMORIA\n");
    return 0;
  }

  (**node).character = character;
  (**node).file = fopen(filename, "r");
  (**node).numDifferentsWords = 0;
  (**node).center = NULL;
  (**node).right = NULL;
  (**node).left = NULL;

  return 1;
}

int tstFileNodeAuxInsertFile(tstFileNode **node, char *character,
                             char *filename) {
  if (*node == NULL) {

    if (character[1] == '\0') {

      tstFileNodeCreateNode(node, *character, filename);

      return 1;

    } else {

      tstFileNodeCreateNode(node, *character, NULL);

      tstFileNodeAuxInsertFile(&((**node).center), ++character, filename);
      return 1;
    }
  }

  if ((**node).character == *character) {

    if (tstFileNodeAuxInsertFile(&((**node).center), ++character, filename))
      return 1;

    return 0;
  }

  if ((**node).character < *character) {

    if (tstFileNodeAuxInsertFile(&((**node).right), character, filename))
      return 1;

    return 0;
  }

  if ((**node).character > *character) {

    if (tstFileNodeAuxInsertFile(&((**node).left), character, filename))
      return 1;

    return 0;
  }
  return 0;
}

int tstFileNodeInsertFile(tstFileNode **node, char *filename) {
  char swap[PATH_MAX];
  char *nameForTree;

  // Esse trecho transforma "inputs/A_Kind_Of_Magic.txt" em
  // "A_Kind_Of_Magic.txt" para evitar desperdicio de memoria na TST de arquivos
  strcpy(swap, filename);
  strtok(swap, "/");               // Splita a string na "/"
  nameForTree = strtok(NULL, "/"); // Pega a segunda parte do split

  return tstFileNodeAuxInsertFile(node, nameForTree, filename);
}

int tstFileNodeInsertInputs(tstFileNode **node, char *dirname, int *qtdFiles) {
  char cwd[PATH_MAX]; // Cria uma string do tamanho maximo do path do sistema
  char filename[PATH_MAX]; // Igual a anterior
  DIR *dir;                // Ponteiro para pasta
  struct dirent *lsdir;

  getcwd(
      cwd,
      sizeof(
          cwd)); // Pega o CURRENT WORKING DIRECTORY Exemplo: mateuspsilva/home
  strcat(cwd, "/");     // Cocatena uma "/". Exemplo: mateuspsilva/home/
  strcat(cwd, dirname); // Cocatena o nome da pasta de inputs Exemplo:
                        // mateuspsilva/home/inputs

  dir = opendir(cwd); // Abre a pasta de inputs

  while ((lsdir = readdir(dir)) !=
         NULL) // Percorre os arquivos da pasta enquanto existirem
  {
    if ((strcmp(lsdir->d_name, "..") != 0) &&
        strcmp(lsdir->d_name, ".") !=
            0) {                 // Trata o "." e ".." comuns do path do linux
      strcpy(filename, dirname); // Copia o nome da pasta de inputs para
                                 // filename Exemplo: inputs
      strcat(filename, "/");     // Cocatena uma "/" Exemplo: inputs/
      strcat(filename, lsdir->d_name); // Cocatena o nome de um arquivo Exemplo:
                                       // inputs/A_Kind_of_Magic.txt
      (*qtdFiles) += 1;
      tstFileNodeInsertFile(node,
                            filename); // Insere o arquivo na TST para arquivos
    }
  }

  closedir(
      dir); // Fecha o ponteiro para pastas, semelhante ao close() para arquivos

  return 1;
}

tstFileNode **tstFileNodeSearch(tstFileNode **raiz, char *character) {
  if (*raiz != NULL && *character != '\0') {

    if ((**raiz).character == *character) {

      if ((**raiz).file != NULL && character[1] == '\0') {

        return raiz;
      } else {

        return tstFileNodeSearch(&(**raiz).center, ++character);
      }
    } else if ((**raiz).character < *character) {

      return tstFileNodeSearch(&(**raiz).right, character);
    } else {

      return tstFileNodeSearch(&(**raiz).left, character);
    }
  }

  return NULL;
}

int tstFileNodeDestroy(tstFileNode **node) {
  if ((*node) != NULL) {
    tstFileNodeDestroy(&(**node).left);
    tstFileNodeDestroy(&(**node).center);
    tstFileNodeDestroy(&(**node).right);
    free((*node));
    (*node) = NULL;
  }

  return 0;
}
