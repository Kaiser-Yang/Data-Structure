#include "stack.h"

void initStack(stack **s){
    (*s) = malloc(sizeof(stack));
    (*s)->data = 0;
    (*s)->nex = NULL;
}
void cleanStack(stack *s){
    stack *cur = s->nex, *las = s;
    while(las){
        free(las);
        las = cur;
        if (cur) cur = cur->nex;
    }
}
bool empty(stack *s){
    return s->nex == NULL;
}
bool push(stack *s, elemType e){
    stack *now = malloc(sizeof(stack));
    now->nex = s->nex;
    now->data = e;
    s->nex = now;
    return true;
}
bool pop(stack *s, elemType *e){
    if (empty(s)) return false;
    stack *cur = s->nex;
    s->nex = cur->nex;
    free(cur);
    return true;
}
bool getTop(stack *s, elemType *e){
    if(empty(s)) return false;
    *e = s->nex->data;
    return true;
}