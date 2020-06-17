#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

#define MAXSIZE 1010
#define NL puts("");
#define elemType int

typedef struct{
    elemType data[MAXSIZE];
    int front, tail;
}queue;

extern void initQueue(queue **q);
extern bool insElem(queue *q, elemType e);
extern bool empty(queue *q);
extern bool pop(queue *q, elemType *e);
extern bool getTop(queue *q, elemType *e);