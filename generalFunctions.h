#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt/tstNode.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "adt/invertedChainedList.h"

int generalFunctionsLoadWords(FILE * fp, char * filename, tstNode ** tstAutoFill, patriciaNode ** patricia);
int generalFunctionsAuxLoadTstFile(tstFileNode *tstFile, char * buffer, int h, tstNode ** tstAutoFill, patriciaNode ** patricia);
int generalFunctionsLoadTstFile(tstFileNode **tstFile, tstNode ** tstAutoFill, patriciaNode ** patricia);

#endif
