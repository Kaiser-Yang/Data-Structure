#include "stack.h"

void initStack(stack *s){
    s->top = 0;
}
void cleanStack(stack *s){
    s->top = 0;
}
bool empty(stack *s){
    return s->top == 0;
}
bool push(stack *s, elemType e){
    if (s->top == MAXSIZE) return false;
    s->data[s->top ++] = e;
    return true;
}
bool pop(stack *s, elemType *e){
    if (empty(s)) return false;
    *e = s->data[-- s->top];
    return true;
}
bool getTop(stack *s, elemType *e){
    if (empty(s)) return false;
    *e = s->data[s->top - 1];
    return true;
}