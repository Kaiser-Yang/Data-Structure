#pragma once

#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define NL puts("");
#define elemType int

typedef struct circularLink{
    elemType data;
    struct circularLink *nex;
}*cirList, node;
typedef void (*CALLBACK)(elemType*);

extern void initList(cirList *L);
extern bool insElem(cirList L, int i, elemType e);
extern bool delElem(cirList L, int i, elemType *e);
extern void destroyList(cirList *L);
extern void traverse(cirList L, CALLBACK f);

