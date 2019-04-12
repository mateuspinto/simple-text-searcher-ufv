#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"

int main() {


    tstFileNode * tstFileInputs, *tstFileStopWords;
    tstNode * tstAutoFill, * tstStopWords;
    patriciaNode * patricia;
    int a;

    tstNodeStartTree(&tstAutoFill);
    tstNodeStartTree(&tstStopWords);
    tstFileNodeStartTree(&tstFileInputs);
    tstFileNodeStartTree(&tstFileStopWords);
    patriciaNodeStartTree(&patricia);


    tstFileNodeInsertInputs(&tstFileStopWords, "stopwords");
    tstFileNodeInsertInputs(&tstFileInputs, "inputs_test");

    //generalFunctionsLoadTstFileOnlyTST(&tstFileStopWords, &tstStopWords);
    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &tstStopWords, &patricia);

    //tstNodeGoThrough(&tstAutoFill);
    patriciaNodeGoThrough(&patricia);
    tstNodeStartTree(&tstStopWords);


    /*patriciaNodeStartTree(&patricia);
    patriciaNodeInsertWord(&patricia, "lord", "teste");
    patriciaNodeInsertWord(&patricia, "blef", "teste");
    patriciaNodeInsertWord(&patricia, "atum", "teste");
    patriciaNodeInsertWord(&patricia, "yeah", "teste");
    patriciaNodeInsertWord(&patricia, "Acaraje", "teste");
    patriciaNodeInsertWord(&patricia, "a", "teste");
    patriciaNodeInsertWord(&patricia, "", "teste");
    patriciaNodeGoThrough(&patricia);*/


	return 0;

}
