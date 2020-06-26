#include "hCode.h"

void createHuffmanCode(huffmanTree ht, huffmanCode hc, int n){
    char *cd = malloc(n * sizeof(char));
    cd[n - 1] = 0;
    for (int i = 1;i <= n;i ++){
        int start = n - 1;
        int par = ht[i].parent, c = i;
        while(par){
            start --;
            if (ht[par].lc == c) cd[start] = '0';
            else cd[start] = '1';
            c = par, par = ht[par].parent;
        }
        strcpy(hc[i], cd + start);
    }
    free(cd);
}