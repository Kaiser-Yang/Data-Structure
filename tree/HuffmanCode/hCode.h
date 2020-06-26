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

typedef char *huffmanCode[MAXN + 1];
typedef struct{
    int weight, parent, lc, rc;
}huffmanNode, huffmanTree[MAXN * 2 + 10];

extern void createHuffmanCode(huffmanTree ht, huffmanCode hc, int n);