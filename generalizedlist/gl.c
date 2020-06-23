#include "gl.h"

GL head(GL L){
    if (L == NULL) return NULL;
    if (L->tag == atom) exit(0);
    else return L->atomHtp.htp.hp;
}
GL tail(GL L){
    if (L == NULL) return NULL;
    if (L->tag == atom) exit(0);
    else return L->atomHtp.htp.tp;
}
int len(GL L){
    int cnt = 0;
    GLNode *cur;
    if (L == NULL) return 0;
    if (L->tag == atom) exit(0);
    if (L->atomHtp.htp.hp == NULL) return 0;
    cur = L;
    while(cur != NULL){
        cnt ++;
        cur = cur->atomHtp.htp.tp;
    }
    return cnt;
}
int dep(GL L){
    int d, max = 0;
    GLNode *cur;
    if (L == NULL) return 1;
    if (L->tag == atom) return 0;
    cur = L;
    while(cur != NULL){
        d = dep(cur->atomHtp.htp.hp);
        if (d > max)  max = d;
        cur = cur->atomHtp.htp.tp;
    }
    return max + 1;
}
int cntAtom(GL L){
    int n1, n2;
    if (L == NULL) return 0;
    if (L->tag == atom) return 1;
    n1 = cntAtom(L->atomHtp.htp.hp);
    n2 = cntAtom(L->atomHtp.htp.tp);
    return n1 + n2;
}
bool copyGL(GL s, GL *t){
    if (s == NULL){
        (*t) = NULL;
        return true;
    }
    *t = malloc(sizeof(GLNode));
    (*t)->tag = s->tag;
    if (s->tag == atom) (*t)->atomHtp.data = s->atomHtp.data;
    else{
        copyGL(s->atomHtp.htp.hp, &((*t)->atomHtp.htp.hp));
        copyGL(s->atomHtp.htp.tp, &((*t)->atomHtp.htp.tp));
    }
    return true;
}