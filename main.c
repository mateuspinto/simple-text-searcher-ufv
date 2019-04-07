#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"

int main() {


    tstFileNode * tstFile;
    tstNode * tst;

    tstNodeStartTree(&tst);
    tstFileNodeStartTree(&tstFile);

    tstFileNodeInsertInputs(&tstFile, "inputs");
    generalFunctionsLoadTstFile(&tstFile, &tst);

    tstNodeGoThrough(&tst);



	return 0;

}
