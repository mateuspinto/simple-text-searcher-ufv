/*
Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
Professora: Doutora Glaucia Braga e Silva
Integrantes (Matricula - Nome):
1278 - Angelo Bernar Tessaro Morelo
3513 - Leandro Lazaro Araujo Vieira
3489 - Mateus Pinto da Silva
*/

#include "generalFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "adt/listaPesquisa.h"
#include "adt/bstNode.h"
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

    // printf("%d\n", (**tstFile).numDifferentsWords);

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

//Funcção de pesquisa:

int generalFunctionsSearch(tstFileNode **tstFile, patriciaNode ** patricia, char *words, int qtdFiles){
    char *word = strtok(words," ");
    int x=0;
    listaPesquisa *listaPesquisaTemp=NULL;
    bstNode *bstPesquisa;
    bstNodeStartTree(&bstPesquisa);

    //Reparte a String pelos seus espaço e pesquisa palavra por palavra atribuindo os arquivos que ela aparece em uma lista encadeada tempoária
    while(word){
        invertedChainedList *listTemp=patriciaNodeSearchWord(patricia, word);
        int qtdFilesAsWord=0;
        //Função recursiva auxiliar para descobrir e atribuir o nome dos arquivos e os seus respectivos pesos na lista encadeada
        generalFunctionsSearchWordAux(tstFile, &listTemp, &listaPesquisaTemp, qtdFiles, &qtdFilesAsWord);
        // puts(word);
        word = strtok(NULL, " ");
        x++;
    }


    // listaPesquisaShow(&listaPesquisaTemp);

    //Verifica se a pesquisa retornou resultados
    if(listaPesquisaTemp!=NULL){

        //Carrega a lista na BST com obejtivo de ordenar os resultados em relação ao seu peso
        generalFunctionsLoadListInBST(&listaPesquisaTemp, &bstPesquisa);

        //Mostra os resultados da pesquisa em ordem de peso do maior para o menor
        bstNodeInOrder(&bstPesquisa);

    }else{
        printf("Sua pesquisa não retornou nenhum resultado :(\n");
    }
    return 0;
}

//Essa função navega até o fim da lista encadeada invertida e só no seu retorno faz os calculos dos pesos, ou seja, ela funciona do final para o inicio da lista
int generalFunctionsSearchWordAux(tstFileNode **tstFile, invertedChainedList **listFiles, listaPesquisa **listaTemp, int qtdFiles, int *qtdFilesAsWord){
    if(*listFiles!=NULL){
        (*qtdFilesAsWord)+=1;
        int ocurrences=(**listFiles).ocurrences;
        int numDifferentsWords=(**tstFileNodeSearch(tstFile, (**listFiles).filename)).numDifferentsWords;
        char *filename=(**listFiles).filename;
        double weight=2.0;
        generalFunctionsSearchWordAux(tstFile, &(**listFiles).next, listaTemp, qtdFiles, qtdFilesAsWord);
        
        weight=(1.0/((double)numDifferentsWords))*(double)ocurrences*(log2((double)qtdFiles)/(double)(*qtdFilesAsWord));
        
        listaPesquisaInsereItem(listaTemp, weight, filename);
    }

    return 0;
}


int generalFunctionsLoadListInBST(listaPesquisa **listaPesquisaTemp, bstNode **bstPesquisa){
    if(*listaPesquisaTemp!=NULL){
        bstNodeInsertFile(bstPesquisa, (**listaPesquisaTemp).wieght, (**listaPesquisaTemp).filename);
        generalFunctionsLoadListInBST(&(**listaPesquisaTemp).proximo, bstPesquisa);
    }

    return 0;
}

int generalFunctionsShowRadicalsAutoFill(tstNode **node, listAutoFill **list, char *word){
    tstNodeSearchRadical(node, word);

    tstNodeGoThrough(tstNodeSearchRadical(node, word), list);
 
    listAutoFillShowItens(list, word);
    return 0;
}

int generalFunctionsGetRadical(listAutoFill **list, char *word, char *string, int index){
    listAutoFill *listTemp=listAutoFillGetItem(list, index);
    if(listTemp!=NULL){
        strcat(word, (*listTemp).word);
    }
    listaAutoFillDestroy(list);
    
    strcat(string, word);

    strcat(string, " ");

    printf("Result: %s\n", string);

    return 1;
}

