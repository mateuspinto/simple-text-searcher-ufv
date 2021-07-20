# Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
# Professora: Doutora Glaucia Braga e Silva
# Integrantes (Matricula - Nome):
# 1278 - Angelo Bernar Tessaro Morelo
# 3513 - Leandro Lazaro Araujo Vieira
# 3489 - Mateus Pinto da Silva

# Nome do executavel
BIN=googla

# Compiladores
CC=clang

# Main e .c dos TADS
SRC= main.c adt/tstNode.c adt/invertedChainedList.c adt/tstFileNode.c adt/patriciaNode.c adt/listaPesquisa.c adt/bstNode.c adt/listAutoFill.c generalFunctions.c

all:
	$(CC) -o $(BIN) $(SRC) -Wall -lm -O3 -march=native -flto

run:
	./$(BIN)

clear:
	rm $(BIN)
