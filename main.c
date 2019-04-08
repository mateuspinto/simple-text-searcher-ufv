#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"

int main() {


    tstFileNode * tstFileInputs, *tstFileStopWords;
    tstNode * tstAutoFill, * tstStopWords;

    tstNodeStartTree(&tstAutoFill);
    tstNodeStartTree(&tstStopWords);
    tstFileNodeStartTree(&tstFileInputs);
    tstFileNodeStartTree(&tstFileStopWords);


    tstFileNodeInsertInputs(&tstFileStopWords, "stopwords");
    tstFileNodeInsertInputs(&tstFileInputs, "inputs_validation");

    generalFunctionsLoadTstFileOnlyTST(&tstFileStopWords, &tstStopWords);
    tstNodeGoThrough(&tstStopWords);
    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &tstStopWords);

    tstNodeGoThrough(&tstAutoFill);



	return 0;

}
