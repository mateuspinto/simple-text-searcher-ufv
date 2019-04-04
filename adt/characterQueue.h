#ifndef CHARACTERQUEUE_H
#define CHARACTERQUEUE_H

typedef struct characterQueue {
    char character;
    struct characterQueue * next;
} characterQueue;

#endif

int characterQueue_startQueue(characterQueue ** node);
int characterQueue_createNode(characterQueue **node, char character);
int characterQueue_queue(characterQueue **node, char *character);
int characterQueue_clean(characterQueue **node);
