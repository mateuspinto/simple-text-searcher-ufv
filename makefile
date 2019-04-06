# change application name here (executable output name)
TARGET=text_organizer

# compiler
CC=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= main.c adt/tst.c adt/invertedChainedList.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clear:
	rm $(TARGET)

debug:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -DDEBUG
