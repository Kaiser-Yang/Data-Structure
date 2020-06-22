#include "matrix.h"

void initMatrix(crossList *L){
    scanf("%d%d%d", &L->m, &L->n, &L->len);//行数， 列数， 非零元个数;
    L->colHead = malloc((L->n + 1) * sizeof(nLink));
    L->rowHead = malloc((L->m + 1) * sizeof(nLink));
    for (int i = 1;i <= L->n;i ++) L->colHead[i] = NULL;
    for (int i = 1;i <= L->m;i ++) L->rowHead[i] = NULL;
    for (int i = 0;i < L->len;i ++){
        node *now = malloc(sizeof(node));
        scanf("%d%d%d", &now->row, &now->col, &now->e);//元素位置及值
        if (L->rowHead[now->row] == NULL || L->rowHead[now->row]->col > now->col){
            now->right = L->rowHead[now->row];
            L->rowHead[now->row] = now;
        }
        else{
            node *cur = L->rowHead[now->row];
            while(cur->right != NULL && cur->right->col < now->col) cur = cur->right;
            now->right = cur->right;
            cur->right = now;
        }
        if (L->colHead[now->col] == NULL || L->colHead[now->col]->row > now->row){
            now->down = NULL;
            L->colHead[now->col] = now;
        }
        else{
            node *cur = L->colHead[now->col];
            while(cur->down != NULL && cur->down->row < now->col) cur = cur->down;
            now->down = cur->down;
            cur->down = now;
        }
    }
}
bool insElem(crossList *L, int x, int y, elemType e){
    if (x <= 0 || x > L->m || y <= 0 || y > L->n || e == 0) return false;
    node *cur = L->rowHead[x];
    while(cur != NULL){
        if (cur->col == y) return false;
        cur = cur->right;
    }
    node *now = malloc(sizeof(node));
    now->col = y, now->row = x, now->e = e;
    L->len ++;
    if (L->rowHead[now->row] == NULL || L->rowHead[now->row]->col > now->col){
        now->right = NULL;
        L->rowHead[now->row] = now;
    }
    else{
        cur = L->rowHead[now->row];
        while(cur->right != NULL && cur->right->col < now->col) cur = cur->right;
        now->right = cur->right;
        cur->right = now;
    }
    if (L->colHead[now->col] == NULL || L->colHead[now->col]->row > now->row){
        now->down = NULL;
        L->colHead[now->col] = now;
    }
    else{
        cur = L->colHead[now->col];
        while(cur->down != NULL && cur->down->row < now->col) cur = cur->down;
        now->down = cur->down;
        cur->down = now;
    }
    return true;
}
void destroyList(crossList *L){
    for (int i = 1;i <= L->m;i ++){
        node *cur = L->rowHead[i];
        if (cur == NULL) continue;
        node *las = cur;
        cur = cur->right;
        while(cur != NULL){
            free(las);
            las = cur;
            cur = cur->right;
        }
        free(las);
    }
    free(L->rowHead);
    free(L->colHead);
}