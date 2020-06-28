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
    int vex, weight;
    struct arcNode *nexarc;
}arcNode;

typedef struct vertex{
    nodeData data;//用于存放点权
    arcNode *firstArc;
}vertex;

typedef struct{
    vertex head[MAXNODE];
    int vexnum, arcnum;
    graphKind kind;
}ajList;

extern void initList(ajList *L, int type);//type为0表示有向图为1 表示无向图
extern void createGraph(ajList *L);