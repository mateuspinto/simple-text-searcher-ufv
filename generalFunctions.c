#include "generalFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "generalFunctions.h"

int generalFunctionsSetNumDifferentsWords(tstNode **arvoreAuxiliar, tstFileNode **tstFile, char *filename, char *word){

    if(tstNodeSearch(arvoreAuxiliar, word)==NULL){
        tstNodeInsertWord(arvoreAuxiliar, word);
        (**tstFile).numDifferentsWords++;
    }

    return 0;

}

int generalFunctionsLoadWords(FILE * fp, char * filename, tstNode ** tstAutoFill, patriciaNode ** patricia, tstFileNode **tstFile){
    char word[45];
    char c;
    int count;
    tstNode *arvoreAuxiliar;
    tstNodeStartTree(&arvoreAuxiliar);

    count = 0;
    while((c = fgetc(fp)) != EOF)
    {
        if((c == ' ' || c == '\n') && count!=0)
        {
            word[count] ='\0';
            tstNodeInsertWord(tstAutoFill, word);
            patriciaNodeInsertWord(patricia, word, filename);
            generalFunctionsSetNumDifferentsWords(&arvoreAuxiliar, tstFile, filename, word);
            count=0;
        }
        else
        {
            if((c>=97 && c<=122) || // Verifica se e uma letra minuscula
                (c>=65 && c<=90)){// Verifica se e uma letra maiscula
    

            if(c>=65 && c<=90) // Caso seja uma letra maiscula, transforma numa minuscula
                c = c+32;

            word[count] = c;
            ++count;
        }
        }
    }

    if(count!=0)
        {
            word[count] ='\0';
            tstNodeInsertWord(tstAutoFill, word);
            patriciaNodeInsertWord(patricia, word, filename);
            generalFunctionsSetNumDifferentsWords(&arvoreAuxiliar, tstFile, filename, word);
        }
    tstNodeDestroy(&arvoreAuxiliar);    

    printf("%d\n", (**tstFile).numDifferentsWords);

    fclose(fp);
    return 1;
}

int generalFunctionsAuxLoadTstFile(tstFileNode *tstFile, char * buffer, int h, tstNode ** tstAutoFill, patriciaNode ** patricia)
{
    if (tstFile != NULL)
    {
        generalFunctionsAuxLoadTstFile(tstFile->left,buffer,h, tstAutoFill, patricia);

        buffer[h] = tstFile->character;
        if ((tstFile->file)!=NULL)
        {

            buffer[h+1] = '\0';
            buffer++;
            generalFunctionsLoadWords(tstFile->file, buffer, tstAutoFill, patricia, &tstFile);
        }

        generalFunctionsAuxLoadTstFile(tstFile->center,buffer,h + 1, tstAutoFill, patricia);

        generalFunctionsAuxLoadTstFile(tstFile->right,buffer,h, tstAutoFill, patricia);

        return 1;
    }

    return 0;
}

int generalFunctionsLoadTstFile(tstFileNode **tstFile, tstNode ** tstAutoFill, patriciaNode ** patricia)
{
    char buffer[PATH_MAX+1];
    return generalFunctionsAuxLoadTstFile(*tstFile,buffer,1, tstAutoFill, patricia);
}