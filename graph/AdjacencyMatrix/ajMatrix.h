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
#define nodeType char

typedef enum{
    DG, UDG//表示有向图和无向图
}graphKind;
typedef struct{
    nodeType vertex[MAXNODE];//第i个结点对应的名字
    bool mp[MAXNODE][MAXNODE];
    int vexnum, arcnum;
    graphKind kind;
}ajMatrix;

extern int locateVertex(ajMatrix *G, nodeType v);//返回v在G中的位置， 及数组下标;
extern void createGraph(ajMatrix *G);
