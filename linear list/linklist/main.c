#include "list.h"

void print(elemType *e){
    printf("%4d", *e);
}
int main(){
    linkList L;
    initList(&L);
    for (int i = 1;i <= 10;i ++) insElem(L, i, i);
    int x;
    delElem(L, 10, &x);
    int ans = delXtoY(L, 2, 90);
    printf("%d\n", ans);
    traverse(L, print);
    NL
    destroyList(&L);
    return 0;
}