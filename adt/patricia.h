#ifndef PATRICIA_H
#define PATRICIA_H

#include<stdlib.h>
#include <sys/time.h>
#define D 8   /* depende de TipoChave */

typedef unsigned char TipoChave; /* a definir, dependendo da aplicacao */
typedef unsigned char TipoIndexAmp;
typedef unsigned char TipoDib;
typedef enum {
  Interno, Externo
} TipoNo;
typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo {
  TipoNo nt;
  union {
    struct {
      TipoIndexAmp Index;
      TipoArvore Esq, Dir;
    } NInterno ;
    TipoChave Chave;
  } NO;
} TipoPatNo;


#endif
