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
    patriciaNodeStartTree(&patricia);
    tstFileNodeStartTree(&tstFileInputs);
    tstFileNodeStartTree(&tstFileStopWords);

    tstFileNodeInsertInputs(&tstFileStopWords, "stopwords");
    tstFileNodeInsertInputs(&tstFileInputs, "inputs_test");

    generalFunctionsLoadTstFileOnlyTST(&tstFileStopWords, &tstStopWords);
    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &tstStopWords, &patricia);

    /* patriciaNodeInsertWord(&patricia, "love", "bohemian");
    patriciaNodeInsertWord(&patricia, "love", "bohemian");
    patriciaNodeInsertWord(&patricia, "love", "bohemian");
    patriciaNodeInsertWord(&patricia, "love", "bohemian");
    patriciaNodeInsertWord(&patricia, "love", "bohemian");
    patriciaNodeInsertWord(&patricia, "lo", "bohemian");
    patriciaNodeInsertWord(&patricia, "hello", "bohemian"); */
    patriciaNodeGoThroughWithOcurrences(&patricia);



	return 0;

}
