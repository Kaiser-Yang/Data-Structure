#include "ajMatrix.h"

int locateVertex(ajMatrix *G, nodeType v){
    for (int i =  0;i < G->vexnum;i ++)
        if (G->vertex[i] == v) return i;
    return -1;//没有这个结点
}
void createGraph(ajMatrix *G){
    int flag;
    scanf("%d%d%d", &G->arcnum, &G->vexnum, &flag);//输入边数和点数
    if (flag) G->kind = UDG;
    else G->kind = DG;
    for (int i = 0;i < G->vexnum;i ++)
        for(int j = 0;j < G->vexnum;j ++) G->mp[i][j] = 0;
    for (int i = 0;i < G->vexnum;i ++){
        char s[10] = "";
        scanf("%s", s);
        G->vertex[i] = s[0];
    }
    for (int i = 0;i < G->arcnum;i ++){
        char u[10], v[10];
        scanf("%s%s", u, v);
        int p1 = locateVertex(G, u[0]), p2 = locateVertex(G, v[0]);
        G->mp[p1][p2] = true;
        if (G->kind == UDG) G->mp[p2][p1] = true;
    }
}