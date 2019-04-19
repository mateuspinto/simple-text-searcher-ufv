#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "adt/bstNode.h"
#include "adt/listaPesquisa.h"
#include "generalFunctions.h"

int main() {

    tstFileNode * tstFileInputs;
    tstNode * tstAutoFill;
    patriciaNode * patricia;
    char search[500]="quer todos";
    int qtdFiles=0;

    tstNodeStartTree(&tstAutoFill);
    patriciaNodeStartTree(&patricia);
    tstFileNodeStartTree(&tstFileInputs);

    tstFileNodeInsertInputs(&tstFileInputs, "giromba", &qtdFiles);

    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &patricia);

    // patriciaNodeGoThroughWithOcurrences(&patricia);

    // bstNode * bst;

    // bstNodeStartTree(&bst);
    // bstNodeInsertFile(&bst, 20, "mateus");
    // bstNodeInsertFile(&bst, 30, "mateus");
    // bstNodeInsertFile(&bst, 40, "mateus");
    // bstNodeInsertFile(&bst, 20, "jorge");
    // bstNodeInsertFile(&bst, 20, "afonso");

    // bstNodeInOrder(&bst);

    // bstNodeDestroy(&bst);

    // bstNodeInOrder(&bst);

    printf("Digite qualquer coisa e tecle enter pra pesquisar:\n");

    scanf("%[^\n]", search);
    /* Limpar o buffer */
    scanf("%*[^\n]"); scanf("%*c");

    generalFunctionsSearch(&tstFileInputs, &patricia, search, qtdFiles);

	return 0;

}
