#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"

int main() {

    tstFileNode * mateus;
    tstFileNodeStartTree(&mateus);
    tstFileNodeInsertInputs(&mateus, "inputs");

    return 1;
}
