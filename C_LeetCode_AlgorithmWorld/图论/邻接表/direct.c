/*
手动构建有向邻接矩阵:
[1,3]
[3,1]
[1,2]
[2,3]
[2,4]
[4,3]
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct edge
{
    int val;
    struct edge* next;
}edge;//添加的边结构

typedef struct areedge
{
    int date;
    edge* firstedge;
}areedge;//头结构,可以看作一个虚拟头节点

typedef struct Graph
{
    int count;//边的数量
    areedge H[5];//0弃而不用
}Graph;//图结构

void initGraph(Graph* G) {
    G->count = 5;
    for (int i = 0; i < 5; i++) {
        G->H[i].firstedge = NULL;
    }
}

void addNode(Graph *G, int u, int v) {
    //u指向v
    edge* eg = (edge*)malloc(sizeof(edge));
    eg->val = v;
    eg->next = G->H[u].firstedge;
    G->H[u].firstedge = eg;//头插法插入节点
}

void printGraph(Graph *G) {
    for (int i = 1; i < 5; i++) {
        printf("%d", i);
        edge* cur = G->H[i].firstedge;
        while (cur != NULL) {
            printf("->%d", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }
}//打印邻接表

int main() {
    Graph G;
    initGraph(&G);
    addNode(&G,1, 3);
    addNode(&G,3, 1);
    addNode(&G,1, 2);
    addNode(&G,2, 3);
    addNode(&G,2, 4);
    addNode(&G,4, 3);
    printGraph(&G);
    return 0;
}


