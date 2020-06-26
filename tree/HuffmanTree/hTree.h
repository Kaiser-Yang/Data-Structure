#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <malloc.h>

#define max(a, b) a > b ? a : b

#define MAXN 1010
#define elemType int
#define NL puts("");

typedef struct{
    int weight, parent, lc, rc;
}hNode, hTree[MAXN * 2 + 10];

extern void createHuffmanTree(hTree ht, int *w, int n);