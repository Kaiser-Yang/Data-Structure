#pragma once

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define elemType int
#define MAXSIZE 1010
#define NL puts("");

typedef void (*CALLBACK)(elemType*);

typedef struct _staticlinkedlist{
    elemType data;
    int nex;
}node, staList[MAXSIZE];

extern void initList();
extern bool insElem(staList L, int i, elemType e, int *cur);
extern bool delElem(staList L, int i, elemType *e, int *cur);
extern void traverse(staList L, CALLBACK f);