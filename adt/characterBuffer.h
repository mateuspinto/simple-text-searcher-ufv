#ifndef CHARACTERBUFFER_H
#define CHARACTERBUFFER_H

typedef struct characterBuffer {
    char character;
    struct characterBuffer * next;
} characterBuffer;

int characterBuffer_startBuffer(characterBuffer ** node);
int characterBuffer_createNode(characterBuffer **node, char character);
int characterBuffer_buff(characterBuffer **node, char character);
char characterBuffer_unbuff(characterBuffer **node);
int characterBuffer_clear(characterBuffer **node);
int characterBuffer_notEmpty(characterBuffer **node);
char characterBuffer_returnCharacter(characterBuffer **node);

#endif
