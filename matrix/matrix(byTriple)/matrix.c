#include "matrix.h"

void initMatrix(matrix *a, int m, int n){
    a->len = 0;
    a->m = m;
    a->n = n;
}
bool insElem(matrix *a, int i, int j, elemType e){
    if (i <= 0 || i > a->m || j <= 0 || j > a->n || e == 0) return false;
    for (int ii = 0;ii < a->len;ii ++) if (a->data[ii].row == i && a->data[ii].col == j) return false;
    for (int ii = 0;ii < a->len;ii ++)
        if (a->data[ii].row >=  i && a->data[ii].col >= j){
            for (int jj = a->len;jj - 1 >= ii;jj --) a->data[jj] = a->data[jj - 1];
            a->data[ii].row = i, a->data[ii].col = j, a->data[ii].e = e;
            a->len ++;
            return true;
        }
    a->data[a->len].row = i, a->data[a->len].col = j, a->data[a->len].e = e;
    a->len ++;
    return true;
}
bool addMatrix(matrix *a, matrix *b, matrix *c){
    if (a->m != b->m || a->n != b->n) return false;
    c->m = a->m, c->n = a->n;
    c->len = 0;
    int i = 0, j = 0;
    while(i < a->len || j < b->len){
        if (i >= a->len){
            while(j < b->len){
                c->data[c->len] = b->data[j];
                c->len ++;
                j ++;
            }
            break;
        }
        if (j >= b->len){
            while(i < a->len){
                c->data[c->len] = a->data[i];
                c->len ++;
                i ++;
            }
            break;
        }
        while(a->data[i].row < b->data[j].row){
            c->data[c->len] = a->data[i];
            c->len ++;
            i ++;
        }
        while(a->data[i].col < b->data[j].col){
            c->data[c->len] = a->data[i];
            c->len ++;
            i ++;
        }
        if (a->data[i].row == b->data[j].row && a->data[i].col == b->data[j].col 
            && a->data[i].e + b->data[j].e){
            c->data[c->len] = a->data[i];
            c->data[c->len].e += b->data[j].e;
            c->len ++;
            i ++, j ++;
        }
        while(a->data[i].row > b->data[j].row){
            c->data[c->len] = b->data[j];
            c->len ++;
            j ++;
        }
        while(a->data[i].col > b->data[j].col){
            c->data[c->len] = b->data[j];
            c->len ++;
            j ++;
        }
        if (a->data[i].row == b->data[j].row && a->data[i].col == b->data[j].col 
        && a->data[i].e + b->data[j].e){
            c->data[c->len] = a->data[i];
            c->data[c->len].e += b->data[j].e;
            c->len ++;
            i ++, j ++;
        }
    }
    return true;
}
void transMatrix(matrix *a, matrix *b){
    b->m = a->n, b->n = a->m; b->len = 0;
    if (a->len > 0){
        for (int i = 1;i <= a->n;i ++){
            for (int j = 0;j < a->len;j ++){
                if (a->data[j].col == i){
                    b->data[b->len] = a->data[j];
                    b->data[b->len].col = a->data[j].row;
                    b->data[b->len].row = a->data[j].col;
                    b->len ++;
                }
            }
        }
    }
}
void fastTransMatrix(matrix *a, matrix *b){
    b->m = a->n, b->n = a->m; b->len = a->len;
    if (a->len > 0){
        int num[a->n + 1], pos[a->n + 1];
        memset(num, 0, sizeof(num));
        memset(pos, 0, sizeof(pos));
        for (int i = 0;i < a->len;i ++) num[a->data[i].col] ++;
        for (int i = 2;i <= a->n;i ++) pos[i] = pos[i - 1] + num[i - 1];
        for (int i = 0;i < a->len;i ++){
            int col = a->data[i].col;
            int p = pos[col];
            b->data[p].col = a->data[i].row;
            b->data[p].row = a->data[i].col;
            b->data[p].e = a->data[i].e;
            pos[col] ++;
        }
    }
}