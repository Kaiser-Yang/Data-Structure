#include "oList.h"

void addEdge(oList *L, int u, int v, int w){
    arcNode *now = malloc(sizeof(arcNode));
    now->headvex = u, now->tailvex = v;
    now->w = w;
    now->hlink = L->head[u].firstin;
    L->head[u].firstin = now;
    now->tlink = L->head[v].firstout;
    L->head[v].firstout = now;
}
void createGraph(oList *L){
    int type;
    scanf("%d%d%d", &L->vexnum, &L->arcnum, &type);
    L->kind = type;
    for (int i = 1;i <= L->vexnum;i ++) scanf("%d", &L->head[i].data);
    for (int i = 1;i <= L->vexnum;i ++) L->head[i].firstin = L->head[i].firstout = NULL;
    for (int i = 1;i <= L->arcnum;i ++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(L, u, v, w);
        if (L->kind == UDG) addEdge(L, v, u, w);
    }
}