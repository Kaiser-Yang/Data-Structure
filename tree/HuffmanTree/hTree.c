#include "hTree.h"

void select(hTree ht, int len, int *p1, int *p2){
    *p1 = 1;
    int minw = ht[1].weight;
    for (int i = 2;i <= len;i ++){
        if (ht[i].weight < minw){
            minw = ht[i].weight;
            *p1 = i;
        }
    }
    if (*p1 != 1) *p2 = 1, minw = ht[1].weight;
    else *p2 = 2, minw = ht[2].weight;
    for (int i = 2;i <= len;i ++){
        if (ht[i].weight < minw && i != *p1){
            minw = ht[i].weight;
            *p2 = i;
        }
    }
}
void createHuffmanTree(hTree ht, int *w, int n){
    int m = n * 2 - 1, p1, p2;
    for (int i = 1;i <= m;i ++){
        ht[i].weight = (i <= n ? w[i] : 0);
        ht[i].parent = ht[i].lc = ht[i].rc = 0;
    }
    for (int i = n + 1;i <= m;i ++){
        select(ht, i-1, &p1, &p2);
        ht[i].weight = ht[p1].weight + ht[p2].weight;
        ht[p1].parent = ht[p2].parent = i;
        ht[i].lc = p1, ht[i].rc = p2;
    }
}