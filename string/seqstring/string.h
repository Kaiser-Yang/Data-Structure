#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>

#define NL puts("");
#define MAXSIZE 1010

typedef struct {
    char ch[MAXSIZE];
    int len;
}string;

extern void initString(string *s, string *t);//将t赋值给s
extern bool insString(string *s, int pos, string *t);
extern bool delString(string *s, int pos, int len);
extern bool comString(string *s, string *t);
extern int posStrnig(string *s, int pos, string *t);
extern int KMP(string *s, int pos, string *t);