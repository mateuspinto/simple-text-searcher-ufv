#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patricia.h"

int Bit(TipoIndexNum i, TipoIndexAmp c, TipoChave k){ 
    /* Verifica se a posição x da plavra eh igual ao index do no interno*/
    if(i<=k.sizeWord){
        if(k.word[i]==c){
            return 1;
        }
    }

    return 0;
}

short EExterno(TipoArvore p){ 
  return (p->nt == Externo);
}


TipoArvore CriaNoExt(TipoChave k)
{ TipoArvore p;
  p = (TipoArvore)malloc(sizeof(TipoPatNo));
  p->nt = Externo; p->NO.Chave = k; return p;
}



TipoArvore Insere(TipoChave k, TipoArvore *t){
  TipoArvore p;
  int i;
  if (*t == NULL){
    return (CriaNoExt(k));
  }else{
    p = *t;
    while (!EExterno(p)){
      if (Bit(p->NO.NInterno.IndexNum, p->NO.NInterno.Index, k) == 1){
        p = p->NO.NInterno.Dir;
      }else{
        p = p->NO.NInterno.Esq;
      }
    }
    /* acha a primeira posição diferente */
    i = 1;
    while ((i <= k.sizeWord) & Bit(p->NO.Chave.word[i], i, k)){
      i++;
    }  
    if (i > k.sizeWord){
        if(p->NO.Chave.sizeWord==k.sizeWord){
            printf("Chave já está na arvore");
            return(*t);
        }
    }else{
        return (InsereEntre(k, t, i));
    }    
  }
}

#include "patricia.h"