#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <malloc.h>

#define max(a, b) a > b ? a : b

#define MAXNODE 1010
#define MAXEDGE 1000010
#define INF 0x3f3f3f3f
#define NL puts("");
#define nodeData int

typedef enum{
    DG, UDG
}graphKind;
typedef struct arcNode{
    int tailvex, headvex, w;
    struct arcNode *hlink, *tlink;
}arcNode;
typedef struct vertex{
    nodeData data;//存放结点权重
    arcNode *firstin , *firstout;
}vertex;
typedef struct{
    vertex head[MAXNODE];
    int vexnum, arcnum;
    graphKind kind;
}oList;

extern void createGraph(oList *L);