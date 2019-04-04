# change application name here (executable output name)
TARGET=text_organizer

# compiler
CC=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= main.c adt/tst.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clean:
	rm $(TARGET)
