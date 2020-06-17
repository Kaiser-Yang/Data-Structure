#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define NL puts("");
#define elemType int

typedef struct __Node{
    elemType data;
    struct __Node *nex;
}queueNode;
typedef struct{
    queueNode *front, *tail;
}queue;

extern void initQueue(queue **q);
extern bool empty(queue *q);
extern bool push(queue *q, elemType e);
extern bool pop(queue *q, elemType *e);
extern bool getFront(queue *q, elemType *e);
extern bool clean(queue *q);
