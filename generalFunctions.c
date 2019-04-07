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

int generalFunctionsLoadWords(FILE * fp, char * filename, tstNode ** tstAutoFill){
    char word[45];
    char c;
    int count;

    count = 0;
    while((c = fgetc(fp)) != EOF)
    {
        if((c == ' ' || c == '\n') && count!=0)
        {
            word[count] ='\0';
            //printf("%s\n", word);

            tstNodeInsertWord(tstAutoFill, word);
            // Inserir aqui palavra na patricia +_+


            word[0]='\0';
            count=0;
        }
        else
        {
            if((c>=97 && c<=122) || // Verifica se e uma letra minuscula
                (c>=65 && c<=90) || // Verifica se e uma letra maiscula
                (c>=48 && c<=57)){ // Verifica se e um numero

            if(c>=65 && c<=90) // Caso seja uma letra maiscula, transforma numa minuscula
                c = c+32;

            word[count] = c;
            ++count;
        }
        }
    }
    fclose(fp);
}

int generalFunctionsAuxLoadTstFile(tstFileNode *tstFile, char * buffer, int h, tstNode ** tstAutoFill)
{
    if (tstFile != NULL)
    {
        generalFunctionsAuxLoadTstFile(tstFile->left,buffer,h, tstAutoFill);

        buffer[h] = tstFile->character;
        if ((tstFile->file)!=NULL)
        {

            buffer[h] = '\0';
            buffer++;
            generalFunctionsLoadWords(tstFile->file, buffer, tstAutoFill);
        }

        generalFunctionsAuxLoadTstFile(tstFile->center,buffer,h + 1, tstAutoFill);

        generalFunctionsAuxLoadTstFile(tstFile->right,buffer,h, tstAutoFill);

        return 1;
    }

    return 0;
}

int generalFunctionsLoadTstFile(tstFileNode **tstFile, tstNode ** tstAutoFill)
{
    char buffer[PATH_MAX];
    return generalFunctionsAuxLoadTstFile(*tstFile,buffer,1, tstAutoFill);
}
