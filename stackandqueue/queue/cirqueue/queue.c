#include "queue.h"

void initQueue(queue **q){
    (*q) = malloc(sizeof(queue));
    (*q)->front = (*q)->tail = 0;
}
bool insElem(queue *q, elemType e){
    if ((q->tail + 1) % MAXSIZE == q->front ) return false;
    q->data[q->tail] = e;
    q->tail = (q->tail + 1) % MAXSIZE;
    return true;
}
bool empty(queue *q){
    return q->front == q->tail;
}
bool pop(queue *q, elemType *e){
    if (empty(q)) return false;
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return true;
}
bool getTop(queue *q, elemType *e){
    if (empty(q)) return false;
    *e = q->data[q->front];
    return true;
}