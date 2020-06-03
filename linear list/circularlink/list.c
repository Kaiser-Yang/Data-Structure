#include "list.h"

void initList(cirList *L){
    (*L) = malloc(sizeof(node));
    (*L)->data = 0;
    (*L)->nex = (*L);
}
bool insElem(cirList L, int i, elemType e){
    if (i <= 0) return false;
    cirList cur = L, las = L;
    while(i --){
        if (cur->nex == L){
            if (i == 0){
                cirList now = malloc(sizeof(node));
                now->data = e;
                now->nex = L;
                cur->nex = now;
                return true;
            }
            return false;
        }
        if (las != cur) las = cur;
        cur = cur->nex;
    }
    cirList now = malloc(sizeof(node));
    now->data = e;
    now->nex = cur;
    las->nex = now;
    return true;
}
void destroyList(cirList *L){
    cirList cur = (*L)->nex, las = *L;
    while(cur != *L){
        free(las);
        las = cur;
        cur = cur->nex;
    }
    free(las);
}
void traverse(cirList L, CALLBACK f){
    cirList cur = L->nex;
    while(cur != L){
        f(&cur->data);
        cur = cur->nex;
    }
}
bool delElem(cirList L, int i, elemType *e){
    if (i <= 0) return false;
    cirList cur = L, las = L;
    while(i --){
        if (cur->nex == L) return false;
        if (las != cur) las = cur;
        cur = cur->nex;
    }
    *e = cur->data;
    las->nex = cur->nex;
    free(cur);
    return true;
}