#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt/tstNode.h"
#include "adt/invertedChainedList.h"
#include "adt/tstFileNode.h"
#include "adt/patriciaNode.h"
#include "adt/bstNode.h"
#include "adt/listaPesquisa.h"
#include "adt/listAutoFill.h"
#include "generalFunctions.h"

int main() {

    tstFileNode * tstFileInputs;
    tstNode * tstAutoFill;
    patriciaNode * patricia;
    listAutoFill *listAutoComplete=NULL;
    char *search=malloc(50*sizeof(char));
    char *pasta=malloc(50*sizeof(char));
    int qtdFiles=0;

    tstNodeStartTree(&tstAutoFill);
    patriciaNodeStartTree(&patricia);
    tstFileNodeStartTree(&tstFileInputs);


    int option=1;

    while(option!=0){
        if(option==1){
            printf("╔═════════════════╗\n");
            printf("║     GUUGLAG     ║\n");
            printf("╚═════════════════╝\n\n");

            printf("Para usar o nosso software de pesquisa selecione uma das opções:\n\n");
            printf("♥ Para sair, digite '0'\n");
            printf("♥ Para mostrar este menu a qualquer momento, digite '1'\n");
            printf("♥ Para inserir arquivos, digite '2'\n");
            printf("♥ Para mostrar todos os arquivos, digite '3'\n");
            printf("♥ Para realizar uma pesquisa, digite '4'\n");
            printf("Opção: ");
            scanf("%d", &option);
            setbuf(stdin, NULL);

        }else if(option==2){

            printf("Insira o nome das pastas onde os arquivos estao: ");

            scanf("%s", pasta);
            setbuf(stdin, NULL);

            tstFileNodeInsertInputs(&tstFileInputs, pasta, &qtdFiles);

            generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &patricia);

            printf("Arquivos inseridos com sucesso!\n");

            printf("Selecione uma nova opção ou digite '1' para retornar ao menu: ");

            scanf("%d", &option);
            setbuf(stdin, NULL);


        }else if(option==3){

            patriciaNodeGoThroughWithOcurrences(&patricia);

            printf("Selecione uma nova opção ou digite '1' para retornar ao menu: ");

            scanf("%d", &option);
            setbuf(stdin, NULL);


        }else if(option==4){

            int index;

            printf("Insira os termos da pesquisa: ");

            scanf("%[^\n]s",search);
            setbuf(stdin, NULL);

            generalFunctionsShowRadicalsAutoFill(&tstAutoFill, &listAutoComplete, search);

            printf("AutoComplete - Digite o indice da palavra que vc deseja pesquisar: ");

            scanf("%d",&index);

            generalFunctionsGetRadical(&listAutoComplete, search, index);
            // listAutoFillShowItens(&listAutoComplete);
            // printf("--------------RESULTADO------------\n\n");

            // generalFunctionsSearch(&tstFileInputs, &patricia, search, qtdFiles);

            // printf("\n\nSelecione uma nova opção ou digite '1' para retornar ao menu: ");

            scanf("%d", &option);
            setbuf(stdin, NULL);

            
        }else{
            printf("Ops! A opção que vc selecionou não existe, por favor selecione uma opção válida ou digite '1' para retornar ao menu: ");
            scanf("%d", &option);
            setbuf(stdin, NULL);

        }
    }

    printf("Obrigado por usar o GULAG, quero dizer, GUUGLAG!\n");

    // tstFileNode * tstFileInputs;
    // tstNode * tstAutoFill;
    // patriciaNode * patricia;
    // char *search=malloc(50*sizeof(char));
    // char *pasta=malloc(50*sizeof(char));
    // int qtdFiles=0;

    // tstNodeStartTree(&tstAutoFill);
    // patriciaNodeStartTree(&patricia);
    // tstFileNodeStartTree(&tstFileInputs);

    // scanf("%[^\n]", pasta);
    // /* Limpar o buffer */
    // scanf("%*[^\n]"); scanf("%*c");

    // tstFileNodeInsertInputs(&tstFileInputs, "giromba", &qtdFiles);

    // generalFunctionsLoadTstFile(&tstFileInputs, &tstAutoFill, &patricia);

    // // patriciaNodeGoThroughWithOcurrences(&patricia);

    // printf("Digite qualquer coisa e tecle enter pra pesquisar:\n");

    // scanf("%[^\n]", search);
    // /* Limpar o buffer */
    // scanf("%*[^\n]"); scanf("%*c");

    // generalFunctionsSearch(&tstFileInputs, &patricia, search, qtdFiles);

	return 0;

}
