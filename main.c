#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "generalFunctions.h"

int main() {

    tstFileNode * tstFileInputs;
    tstNode * tstAutoFill;
    patriciaNode * patricia;

    char teste[200];

    tstNodeStartTree(&tstAutoFill);
    patriciaNodeStartTree(&patricia);
    tstFileNodeStartTree(&tstFileInputs);

    tstFileNodeInsertInputs(&tstFileInputs, "inputs");

    generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &patricia);

    patriciaNodeGoThroughWithOcurrences(&patricia);

    scanf("%s",teste);

    tstFileNodeSearch(&tstFileInputs, teste);

    // tstNodeSearch(&tstAutoFill, teste);

	return 0;

}
