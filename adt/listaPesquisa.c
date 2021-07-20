/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM
ARVORES DIGITAIS Professora: Doutora Glaucia Braga e Silva Integrantes
(Matricula - Nome): 1278 - Angelo Bernar Tessaro Morelo 3513 - Leandro Lazaro
Araujo Vieira 3489 - Mateus Pinto da Silva
*/

#include "listaPesquisa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listaPesquisaInsereItem(listaPesquisa **ptr, double weight,
                            char *filename) {
  if (*ptr == NULL) {
    *ptr = malloc(sizeof(listaPesquisa));
    (**ptr).wieght = weight;
    (**ptr).filename = filename;
    (**ptr).proximo = NULL;

    return 0;
  } else {
    if (!strcmp((**ptr).filename, filename)) {
      (**ptr).wieght += weight;

      return 1;
    } else {
      listaPesquisaInsereItem(&(**ptr).proximo, weight, filename);
    }
  }

  return 0;
}

int listaPesquisaDestroy(listaPesquisa **ptr) {
  if (*ptr != NULL) {
    listaPesquisaDestroy(&(**ptr).proximo);
    free(*ptr);
    *ptr = NULL;
  }

  return 0;
}

int listaPesquisaShow(listaPesquisa **ptr) {
  if (*ptr != NULL) {
    printf("Arquivo: %s | Peso: %lf\n", (**ptr).filename, (**ptr).wieght);
    listaPesquisaShow(&(**ptr).proximo);
  }

  return 0;
}
