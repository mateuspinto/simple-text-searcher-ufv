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

    tstNodeStartTree(&tstAutoFill);
    tstNodeStartTree(&tstStopWords);
    tstFileNodeStartTree(&tstFileInputs);
    tstFileNodeStartTree(&tstFileStopWords);
    patriciaNodeStartTree(&patricia);


    tstFileNodeInsertInputs(&tstFileStopWords, "stopwords");
    tstFileNodeInsertInputs(&tstFileInputs, "inputs_validation");

    generalFunctionsLoadTstFileOnlyTST(&tstFileStopWords, &tstStopWords);
    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &tstStopWords, &patricia);

    tstNodeGoThrough(&tstAutoFill);

    /*
     patriciaNodeStartTree(&patricia);
    patriciaNodeInsertWord(&patricia, "another", "teste");
    patriciaNodeInsertWord(&patricia, "guy", "teste");
    patriciaNodeInsertWord(&patricia, "of", "teste");
    patriciaNodeInsertWord(&patricia, "yeah", "teste");
    patriciaNodeInsertWord(&patricia, "Acaraje", "teste");
    patriciaNodeInsertWord(&patricia, "Sapucai", "teste");
    patriciaNodeInsertWord(&patricia, "", "teste");
    patriciaNodeGoThrough(&patricia);
    */

	return 0;

}
