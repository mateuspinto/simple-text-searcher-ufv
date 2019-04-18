# change application name here (executable output name)
TARGET=text_organizer.o

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= main.c adt/tstNode.c adt/invertedChainedList.c adt/tstFileNode.c adt/patriciaNode.c adt/bstNode.c generalFunctions.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clear:
	rm $(TARGET)

debug:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -DDEBUG -O3

clang:
	$(CCO) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -O3