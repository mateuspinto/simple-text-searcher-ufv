#ifndef PATRICIA_H
#define PATRICIA_H

#include<stdlib.h>
#include <sys/time.h>
#define D 8   /* depende de TipoChave */

typedef struct{
    char *word;
    int sizeWord;
}TipoChave; /* a definir, dependendo da aplicacao */
typedef unsigned char TipoIndexAmp;
typedef unsigned char TipoIndexNum;
typedef enum {
  Interno, Externo
} TipoNo;
typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo {
  TipoNo nt;
  union {
    struct {
      TipoIndexAmp Index;
      TipoIndexNum IndexNum;
      TipoArvore Esq, Dir;
    } NInterno ;
    TipoChave Chave;
  } NO;
} TipoPatNo;


#endif