#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define NL puts("");
#define MAXSIZE 1010
#define elemType int 

typedef struct _crossLinkedList{
    int row, col;
    elemType e;
    struct _crossLinkedList *right, *down;
}node, *nLink;
typedef struct {
    nLink *rowHead, *colHead;
    int m, n, len;
}crossList;

extern void initMatrix(crossList *L);
extern bool insElem(crossList *L, int x, int y, elemType e);//在i， j处插入e
extern void destroyList(crossList *L);