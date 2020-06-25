#include "tree.h"

void initTree(bTree *rt){
    (*rt) = NULL;
}
void destroyTree(bTree rt){
    if (rt == NULL) return ;
    bNode *lc = rt->lc, *rc = rt->rc;
    free(rt);
    if (lc != NULL) destroyTree(lc);
    if (rc != NULL) destroyTree(rc);
}
void createTree(bTree *rt){
    char ch;
    ch = getchar();
    if (ch == '.' || ch == '\n') *rt = NULL;
    else{
        *rt = malloc(sizeof(bNode));
        (*rt)->data = ch;
        createTree(&((*rt)->lc));
        createTree(&((*rt)->rc));
    }
}
bool empty(bTree rt){
    return rt == NULL;
}
void cleanlr(bTree rt){
    if (rt == NULL) return ;
    bNode *lc = rt->lc, *rc = rt->rc;
    if (lc != NULL) destroyTree(lc), free(lc);
    if (rc != NULL) destroyTree(rc), free(rc);
}
extern void clean(bTree rt){
    cleanlr(rt);
    rt = NULL;
}
void OLR(bTree rt){
    if (rt == NULL) return ;
    printf("%c ", rt->data);
    OLR(rt->lc);
    OLR(rt->rc);
}
void LOR(bTree rt){
    if (rt == NULL) return ;
    OLR(rt->lc);
    printf("%c ", rt->data);
    OLR(rt->rc);
}
void LRO(bTree rt){
    if (rt == NULL) return ;
    LRO(rt->lc);
    LRO(rt->rc);
    printf("%c ", rt->data);
}
void traverse(bTree rt, int ope){
    if (ope == 1) OLR(rt), NL
    else if (ope == 2) LOR(rt), NL
    else if (ope == 3) LRO(rt), NL
}
int dep(bTree rt){
    int d = 0;
    if (rt == NULL) return 0;
    d = max(d, dep(rt->lc));
    d = max(d, dep(rt->rc));
    return d + 1;
}
void printTree(bTree rt, int dep){
    if (rt == NULL) return ;
    printTree(rt->rc, dep + 1);
    for (int i = 0;i < dep;i ++) putchar(' ');
    printf("%c\n", rt->data);
    printTree(rt->lc, dep + 1);
}
void inOrder(bTree rt){
    int top = 0;
    bNode *cur = rt;
    bNode *s[MAXN];
    do{
        while(cur != NULL){
            top ++;
            s[top] = cur;
            cur = cur->lc;
        }
        if (top != 0){
            cur = s[top];
            top --;
            printf("%c ", cur->data);
            cur = cur->rc;
        }
    }while(cur != NULL || top != 0);
    NL
}
void postOrder(bTree rt){
    bNode *s[MAXN];
    int top = 0;
    bNode *las = NULL, *now = rt;
    while(now != NULL || top != 0){
        if (now != NULL){
            top ++;
            s[top] = now->lc;
        }
        else{
            now = s[top];
            if (now->rc == NULL || now->rc == las){
                top --;
                printf("%c ", now->data);   
                las = now;
                now = NULL;
            }
            else now = now->rc;
        }
    }
    NL
}
void preOrder(bTree rt){
    bNode *s[MAXN];
    int top = 0;
    bNode *now = rt;
    if (now == NULL) return ;
    s[++ top] = now;
    while(now != NULL || top != 0){
        now = s[top];
        top --;
        printf("%c ", now->data);
        top ++;
        s[top] = now->rc;
        top ++;
        s[top] = now->lc;
    }
    NL
}
bNode *inPre(bTree id){//中序线索化中找结点的前驱
    if (id->Ltag == 1) return id->lc;
    bNode *i;
    for (i = id->lc;i->Rtag == 0;i = i->rc);
    return i;
}
bNode *inNex(bTree id){//中序线索化中找结点的后继
    if (id->Rtag == 1) return id->rc;
    bNode *i;
    for (i = id->rc;i->Ltag == 0;i = i->lc);
    return i;
}