#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tst.h"
#include "adt/invertedChainedList.h"
//#include "adt/patricia.h"

int main(int argc, char *argv[]){
    invertedChainedList * mateus;
    invertedChainedListStartList(&mateus);
    invertedChainedListInsertNode(&mateus, "Jurandir.txt");
    invertedChainedListInsertNode(&mateus, "asdas.txt");
    invertedChainedListInsertNode(&mateus, "aa.txt");
    invertedChainedListInsertNode(&mateus, "Jurandir.txt");

    invertedChainedListGoThrough(&mateus);
  return 0;
}
