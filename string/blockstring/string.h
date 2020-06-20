#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

#define NL puts("");
#define BLOCKSIZE 4

typedef struct _blockString{
    char ch[BLOCKSIZE];
    int len;
    struct _blockString *nex;
}block;
typedef struct{
    block *head, *tail;
    int len;
}blString;

extern void initString(blString **s);
extern bool assString(blString *s, char*t);//将t赋值给s
extern bool insString(blString *s, int pos, char *t);
extern bool delString(blString *s, int pos, int len);
extern bool comString(blString *s, blString *t);
extern int posStrnig(blString *s, int pos, blString *t);