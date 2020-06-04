#include "dblist.h"

void initList(dbList *L){
    (*L) = malloc(sizeof(node));
    (*L)->nex = (*L)->pre = (*L);
    (*L)->data = 0;
}
bool insElem(dbList L, int i, bool ope, elemType e){
    if (i <= 0) return false;
    dbList cur = L;
    while(i --){
        if (cur->nex == L){
            if (i == 0){
                if (ope == 0) return false;
                if (ope == 1){
                    dbList now = malloc(sizeof(node));
                    now->data = e;
                    now->nex = cur->nex;
                    cur->nex->pre = now;
                    cur->nex = now;
                    now->pre = cur;
                }
            }
            return false;
        }
        cur = cur->nex;
    }
    if (i == 0) cur = cur->nex;
    dbList now = malloc(sizeof(node));
    now->data = e;
    now->nex = cur->nex;
    cur->nex->pre = now;
    cur->nex = now;
    now->pre = cur;
    return true;
}
bool delElem(dbList L, int i, elemType *e){
    if (i <= 0) return false;
    dbList cur = L;
    while(i --){
        if (cur->nex == L) return false;
        cur = cur->nex;
    }
    cur->pre->nex = cur->nex;
    *e = cur->data;
    cur->nex->pre = cur->pre;
    free(cur);
    return true;
}
void destroyList(dbList L){
    dbList cur = L->nex;
    while(cur->nex != L){
        free(cur->pre);
        cur = cur->nex;
    }
    if (cur->pre == cur){
        free(cur);
        return ;
    }
    free(cur->pre);
    free(cur);
}
void traverse(dbList L, CALLBACK f){
    dbList cur = L->nex;
    while(cur != L){
        f(&cur->data);
        cur = cur->nex;
    }
}