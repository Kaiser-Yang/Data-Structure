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
    elemType data;
    struct seqStack *nex;
}stack;

extern void initStack(stack **s);
extern void cleanStack(stack *s);
extern bool push(stack *s, elemType e);
extern bool pop(stack *s, elemType *e);
extern bool getTop(stack *s, elemType *e);
extern bool empty(stack *s);