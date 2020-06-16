#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#define elemType int
#define NL puts("");
#define MAXSIZE 1010

typedef struct seqStack{
    int data[MAXSIZE];
    int top1, top2;
}stack;

extern void initStack(stack *s);
extern void cleanStack(stack *s, int ope);
extern bool push(stack *s, int ope, elemType e);
extern bool pop(stack *s, int ope, elemType *e);
extern bool getTop(stack *s, int ope, elemType *e);
extern bool empty(stack *s, int ope);