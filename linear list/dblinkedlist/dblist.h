#pragma once

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define elemType int
#define NL puts("");

typedef void (*CALLBACK)(elemType*);

typedef struct _dbList{
    elemType data;
    struct _dbList *pre, *nex;
}*dbList, node;

extern void initList(dbList *L);
extern bool insElem(dbList L, int i, bool ope, elemType e);//ope = 1表示插入到i的前面， 等于0表示插入到i的后面
extern bool delElem(dbList L, int i, elemType *e);
extern void destroyList(dbList L);
extern void traverse(dbList L, CALLBACK f);