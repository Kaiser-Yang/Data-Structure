#include "list.h"

#define NL puts("");

void print(int* e){
    printf("%4d", *e);
}//CALLBACK函数
int main(){
    seqList list;
    listPtr L = &list;
    initList(&L);
    for (int i = 1;i <= 10;i ++) insElem(L, i, i + 10);
    traverse(L, print);
    NL;
    separateList(L);
    traverse(L, print);
    NL;
    return 0;
}