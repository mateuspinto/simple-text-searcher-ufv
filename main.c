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
    patriciaNodeStartTree(&patricia);
    tstFileNodeStartTree(&tstFileInputs);
    tstFileNodeStartTree(&tstFileStopWords);

    tstFileNodeInsertInputs(&tstFileStopWords, "stopwords");
    tstFileNodeInsertInputs(&tstFileInputs, "inputs");

    generalFunctionsLoadTstFileOnlyTST(&tstFileStopWords, &tstStopWords);
    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &tstStopWords, &patricia);

    
    patriciaNodeGoThroughWithOcurrences(&patricia);


	return 0;

}
