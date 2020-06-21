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

typedef struct {
    int row, col;
    elemType e;
}triple;
typedef struct {
    triple data[MAXSIZE];
    int m, n, len;
}matrix;

extern void initMatrix(matrix *a, int m, int n);//初始为m行n列的矩阵
extern bool insElem(matrix *a, int i, int j, elemType e);//在i， j处插入e
extern bool addMatrix(matrix *a, matrix *b, matrix *c);
extern void transMatrix(matrix *a, matrix *b);//将a转置后的结果放到b， a不变
extern void fastTransMatrix(matrix *a, matrix *b);