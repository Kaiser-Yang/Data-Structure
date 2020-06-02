#include "list.h"

void initList(linkList *L){
    (*L) = (linkList)malloc(sizeof(node));
    (*L)->data = 0;
    (*L)->nex = NULL;
}
bool insElem(linkList L, int i, elemType e){
    if (i <= 0) return false;
    linkList cur = L, las = cur;
    while(i --){
        if (cur->nex == NULL){
            if (i == 1){
                linkList now = malloc(sizeof(node));
                now->data = e;
                now->nex = NULL;
                cur->nex = now;
                return true;
            }
            return false;
        }
        if (las != cur) las = cur;
        cur = cur->nex;
    }
    linkList now = malloc(sizeof(node));
    now->data = e;
    las->nex = now;
    now->nex = cur;
    return true;
}
void traverse(linkList L, CALLBACK f){
    linkList cur = L->nex;
    while(cur != NULL){
        f(&(cur->data));
        cur = cur->nex;
    }
}
int delXtoY(linkList L, elemType x, elemType y){
    if (x > y){
        elemType t = x;
        x = y;
        y = t;
    }
    linkList cur1 = L->nex, las = L;
    while(cur1 && cur1->data < x){
        las = cur1;
        cur1 = cur1->nex;
    }
    if (cur1 == NULL) return 0;
    linkList cur2 = cur1;
    while(cur2 && cur2->data <= y) cur2 = cur2->nex;
    int ans = 0;
    las->nex = cur2;
    las = cur1;
    cur1 = cur1->nex;
    while(las != cur2){
        free(las);
        ans ++;
        las = cur1;
        if (cur1 != NULL) cur1 = cur1->nex;
    }
    return ans;
}
bool destroyList(linkList *L){
    if ((*L) == NULL) return false;
    linkList p = *L, q = (*L)->nex;
    while(p != NULL){
        free(p);
        p = q;
        if (q != NULL) q = q->nex;
    }
    return true;
}
bool delElem(linkList L, int i, elemType *e){
    if (i <= 0) return false;
    linkList cur = L, las = L;
    while(i --){
        if (cur->nex == NULL) return false;
        if (las != cur) las = cur;
        cur = cur->nex;
    }
    las->nex = cur->nex;
    *e = cur->data;
    free(cur);
    return true;
}
int locateElem(linkList L, elemType e){
    linkList cur = L->nex;
    int pos = -1, i = 1;
    while(cur){
        if (cur->data == e){
            pos = i;
            break;
        }
        cur = cur->nex;
        i ++;
    }
    return pos;
}
int getElem(linkList L, int i){
    if (i < 1) return -1;
    linkList cur = L->nex;
    while(cur != NULL){
        i --;
        if (i == 0) return cur->data;
        cur = cur->nex;
    }
    return -1;
}
void mergeLink(linkList A, linkList B, linkList C){
    linkList cur1 = A->nex;
    linkList cur2 = B->nex;
    while(cur1 != NULL || cur2 != NULL){
        if (cur2 == NULL || (cur1 != NULL && cur1->data <= cur2->data)){
            C->nex = cur1;
            cur1 = cur1->nex;
            C = C->nex;
        }
        else {
            C->nex = cur2;
            cur2 = cur2->nex;
            C = C->nex;
        }
    }
}
void sortLink(linkList L){
    linkList i, j;
    for (i = L->nex;i != NULL;i = i->nex)
        for (j = L->nex;j->nex != NULL;j = j->nex)
            if (j->data > j->nex->data){
                elemType t = j->data;
                j->data = j->nex->data;
                j->nex->data = t;
            }
}
int lenLink(linkList L){
    int i = 0;
    linkList cur = L->nex;
    while(cur){
        cur = cur->nex;
        i ++;
    }
    return i;
}