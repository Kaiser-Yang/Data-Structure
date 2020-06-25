#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <malloc.h>

#define max(a, b) a > b ? a : b

#define MAXN 1010
#define elemType char
#define NL puts("");

typedef struct node{
    int data;
    bool Ltag, Rtag;//用于二叉树线索化， 为1表示没有左或右儿子
    struct node *lc, *rc;
}bNode, *bTree;

extern void initTree(bTree *rt);
extern void destroyTree(bTree rt);
extern void createTree(bTree *rt);
extern bool empty(bTree rt);
extern void clean(bTree rt);
extern void traverse(bTree rt, int ope);//ope == 1, 2, 3，先 中 后
extern int dep(bTree rt);
extern void printTree(bTree rt, int dep);
extern void inOrder(bTree rt);
extern void postOrder(bTree rt);
extern bNode *inPre(bTree id);
extern bNode *inNex(bTree id);