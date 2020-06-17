#include "queue.h"


void initQueue(queue **q){
    (*q) = malloc(sizeof(queue));
    (*q)->front = NULL;
    (*q)->tail = NULL;
}
bool empty(queue *q){
    return q->tail == NULL;
}
bool push(queue *q, elemType e){
    queueNode *now = malloc(sizeof(queueNode));
    now->data = e;
    now->nex = NULL;
    if (q->tail == NULL){
         q->front = q->tail = now;
         return true;
    }
    q->tail->nex = now;
    q->tail = now;
    return true;
}
bool pop(queue *q, elemType *e){
    if (empty(q)) return false;
    queueNode *cur = q->front;
    if (q->front == q->tail){
        q->front = q->tail = NULL;
        free(cur);
        return true;
    }
    q->front = q->front->nex;
    free(cur);
    return true;
}
bool getFront(queue *q, elemType *e){
    if (empty(q)) return false;
    *e = q->front->data;
    return true;
}
bool clean(queue *q){
    queueNode *cur = q->front, *las = q->front;
    while(cur != NULL){
        cur = cur->nex;
        free(las);
        las = cur;
    }
    free(q);
    return true;
}