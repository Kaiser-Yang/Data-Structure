#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

#define atomType int

typedef enum{
    atom, list
}elemTag;

typedef struct _GLNode{
    elemTag tag;
    union{
        atomType data;
        struct{
            struct _GLNode *hp, *tp;//表头和表尾
        }htp;
    }atomHtp;
}GLNode, *GL;

extern GL head(GL L);
extern GL tail(GL L);
extern int len(GL L);
extern int cntAtom(GL L);
extern bool copyGL(GL s, GL *t);