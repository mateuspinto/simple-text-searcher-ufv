# Trabalho Pratico 1 de Algoritimos E Estruturas de Dadados II - APLICACAO COM ARVORES DIGITAIS
# Professora: Doutora Glaucia Braga e Silva
# Integrantes (Matricula - Nome):
# 1278 - Angelo Bernar Tessaro Morelo
# 3513 - Leandro Lazaro Araujo Vieira
# 3489 - Mateus Pinto da Silva

# Nome do executavel
TARGET=text_organizer.o

# Compiladores
CC=gcc
CCO=clang

# Warnings
WARN=-Wall

CCFLAGS=$(WARN)


# Main e .c dos TADS
SRC= main.c adt/tstNode.c adt/invertedChainedList.c adt/tstFileNode.c adt/patriciaNode.c adt/listaPesquisa.c adt/bstNode.c adt/listAutoFill.c generalFunctions.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clear:
	rm $(TARGET)

clang:
	$(CCO) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -O3