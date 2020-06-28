#include "ajList.h"

void initList(ajList *L, int type){
    L->arcnum = L->vexnum = 0;
    L->kind = type;
}
void addEdge(ajList *L, int u, int v, int w){
    arcNode *now = malloc(sizeof(arcNode));
    now->vex = v;
    now->weight = w;
    now->nexarc = L->head[u].firstArc;
    L->head[u].firstArc = now;
}
void createGraph(ajList *L){
    scanf("%d%d%d", &L->vexnum, &L->arcnum, &L->kind);
    for (int i = 1;i <= L->vexnum;i ++) L->head[i].firstArc = NULL;
    for (int i = 1;i <= L->vexnum;i ++) scanf("%d", &L->head[i].data);
    for (int i = 1;i <= L->arcnum;i ++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(L, u, v, w);
        if (L->kind == UDG) addEdge(L, v, u, w);
    }
}