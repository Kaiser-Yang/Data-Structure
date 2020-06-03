#include "list.h"

void print(elemType *e){
    printf("%4d", *e);
}
int main(){
    srand(time(0));
    cirList L;
    initList(&L);
    for (int i = 1;i <= 1;i ++) insElem(L, i, rand() % 100);
    traverse(L, print);
    NL
    int x;
    delElem(L, 1, &x);
    printf("%d\n", x);
    delElem(L, 11,&x);
    printf("%d\n", x);
    traverse(L, print);
    NL
    destroyList(&L);
    return 0;
}