#include "list.h"

void initList(listPtr *L){
    memset(L->elem, 0, sizeof(L->elem));
    (*L)->last  = - 1;
}
int lenList(listPtr L){
    return L->last + 1;
}
bool emptyList(listPtr L){
    return L->last == -1;
}
elemType getElem(listPtr L, int i){
    if (i - 1 > L->last || i - 1 < 0) return -1;
    return L->elem[i - 1];
}
void traverse(listPtr L, CALLBACK f){
    for (int i = 0;i <= L->last;i ++) f(&L->elem[i]);
}
bool insElem(listPtr L, int i, elemType e){
    i --;
    if (i < 0 || i > L->last + 1) return false;
    L->last ++;
    for (int j = L->last;j > i;j --) L->elem[j] = L->elem[j - 1];
    L->elem[i] = e;
    return true;
}
bool delElem(listPtr L, int i, elemType *e){
    i --;
    if (i < 0 || i > L->last) return false;
    L->last --;
    *e = L->elem[i];
    for (int j = i;j <= L->last;j ++) L->elem[j] = L->elem[j + 1];
    return true;
}
int locatElem(listPtr L, elemType e){
    for (int i = 0;i <= L->last;i ++)
        if (L->elem[i] == e) return i + 1;
    return -1;
}
int delElemXtoY(listPtr L, elemType x, elemType y){
    if (x > y){
        int t = x;
        x = y;
        y = t;        
    }
    int pos[MAXSIZE];
    int lenPos = -1;
    int ans = 0;
    for (int i = 0;i <= L->last;i ++){
        if (L->elem[i] >= x && L->elem[i] <= y) ans ++;
        if (L->elem[i] >= x && L->elem[i] <= y && (i == 0 || L->elem[i - 1] < x || L->elem[i - 1] > y)) pos[++lenPos] = i;
        else if (L->elem[i] >= x && L->elem[i] <= y && (i == L->last || L->elem[i + 1] < x || L->elem[i + 1] > y)) pos[++lenPos] = i;
    }
    if (ans == 0) return 0;
    int nowpos = pos[0];
    int i = 1;
    while(nowpos <= L->last - ans){
        int cnt = 1;
        while(true){
            if (i + 1 <= lenPos && pos[i] + cnt >= pos[i + 1]){
                i += 2;
                break;
            }
            L->elem[nowpos] = L->elem[pos[i] + cnt];
            cnt ++, nowpos ++;
            if (nowpos > L->last - ans) break;
        }
    }
    L->last -= ans;
    return ans;
}