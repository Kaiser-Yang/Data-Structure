#include "stack.h"

void initStack(stack *s){
    s->top1 = -1;
    s->top2 = MAXSIZE;
}
void cleanStack(stack *s, int ope){
    if (ope == 1 || ope == 0) s->top1 = -1;
    if (ope == 2 || ope == 0) s->top2 = MAXSIZE;
}
bool empty(stack *s, int ope){
    if (ope == 1) return s->top1 == 0;
    return s->top2 == MAXSIZE;
}
bool push(stack *s, int ope, elemType e){
    if (ope == 1){
        if (s->top1 + 1 == s->top2) return false;
        s->data[++ s->top1] = e;
        return true;
    }
    if (s->top1 + 1 == s->top2) return false;
    s->data[-- s->top2] = e;
    return true;
}
bool pop(stack *s, int ope, elemType *e){
    if (empty(s, ope)) return false;
    if (ope == 1) *e = s->data[s->top1 --];
    else *e = s->data[s->top2 ++];
    return true;
}
bool getTop(stack *s, int ope, elemType *e){
    if (empty(s, ope)) return false;
    if (ope == 1) *e = s->data[s->top1];
    else *e = s->data[s->top2];
    return true;
}