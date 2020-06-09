#include "list.h"

void initList(staList L, int *cur){
    L[0].nex = -1;
    for (int i = 1;i < MAXSIZE - 1;i ++) L[i].nex = i + 1;
    L[MAXSIZE - 1].nex = -1;
    *cur = 1;
}
bool insElem(staList L, int i, elemType e, int *cur){
    int temp = *cur;
    *cur = L[*cur].nex;
    L[temp].data = e;
    int pos = 0;
    while(i --){
        if (pos == -1) return false;
        if (i == 0){
            L[temp].nex = L[pos].nex;
            L[pos].nex = temp;
            return true;
        }
        pos = L[pos].nex;
    }
    return true;
}
bool delElem(staList L, int i, elemType *e, int *cur){
    int pos = 0, las = 0;
    while(i --){
        if (las != pos) las = pos;
        if (pos == -1) return false;
        pos = L[pos].nex;
    }
    if (pos == -1) return false;
    L[las].nex = L[pos].nex;
    L[pos].nex = *cur;
    *cur = pos;
    return true;
}
void traverse(staList L, CALLBACK f){
    int cur = 0;
    while(cur != -1){
        cur = L[cur].nex;
        if (cur != -1) f(&L[cur].data);
    }
}