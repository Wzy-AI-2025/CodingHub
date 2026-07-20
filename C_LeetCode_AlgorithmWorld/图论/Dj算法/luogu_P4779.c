#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cnt = 0;

typedef struct Edge {
    int to;
    int next;
    int weight;
} Edge;

typedef struct Graph {
    Edge *nodes;
    int *Gh;
} Graph;

void initGraph(int count, int n, Graph *G) {
    G->nodes = (Edge*)malloc(sizeof(Edge) * count);
    G->Gh = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        G->Gh[i] = -1;
    }
}

void addEdge(int u, int v, int weight, Graph *G) {
    G->nodes[cnt].to = v;
    G->nodes[cnt].weight = weight;
    G->nodes[cnt].next = G->Gh[u];
    G->Gh[u] = cnt;
    cnt++;
}

typedef struct heapNode {
    int point;
    int data;
} heapNode;

typedef struct MinHeap {
    heapNode *heaps;
    int size;
    int *index;
} MinHeap;

void initMinHeap(int n, MinHeap *M) {
    M->heaps = (heapNode*)malloc(sizeof(heapNode) * (n + 1));
    M->index = (int*)malloc(sizeof(int) * (n + 1));
    M->size = 0;
    for (int i = 0; i <= n; i++) {
        M->index[i] = -1;
    }
}

void swap(int i, int j, MinHeap *M) {
    heapNode cur = M->heaps[i];
    M->heaps[i] = M->heaps[j];
    M->heaps[j] = cur;
    M->index[M->heaps[i].point] = i;
    M->index[M->heaps[j].point] = j;
}

void up(int i, MinHeap *M) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (M->heaps[i].data < M->heaps[parent].data) {
            swap(i, parent, M);
            i = parent;
        } else {
            break;
        }
    }
}

void down(int i, MinHeap *M) {
    int min = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < M->size && M->heaps[left].data < M->heaps[min].data) min = left;
    if (right < M->size && M->heaps[right].data < M->heaps[min].data) min = right;
    if (min != i) {
        swap(i, min, M);
        down(min, M);
    }
}

//  核心改动：内部统一更新 distance
void Cdata(int i, MinHeap *M, int new_dist, int *distance) {
    int index = M->index[i];
    
    if (index != -1) {
        // 节点已在堆中，检查是否需要更新
        if (new_dist < M->heaps[index].data) {
            M->heaps[index].data = new_dist;
            distance[i] = new_dist;  //  内部更新
            up(index, M);
        }
        return;
    }
    
    // 新节点入堆
    M->heaps[M->size].point = i;
    M->heaps[M->size].data = new_dist;
    distance[i] = new_dist;  //  内部更新
    M->index[i] = M->size;
    M->size++;
    up(M->size - 1, M);
}

heapNode popMin(MinHeap *M) {
    heapNode cur = M->heaps[0];
    M->index[cur.point] = -1;
    M->heaps[0] = M->heaps[--M->size];
    if (M->size > 0) {
        M->index[M->heaps[0].point] = 0;
    }
    down(0, M);
    return cur;
}

int main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    
    Graph G;
    initGraph(m, n, &G);
    
    MinHeap M;
    initMinHeap(n, &M);
    
    int u, v, weight;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight, &G);
    }
    
    int record[n + 1];
    int distance[n + 1];  // 改名为 distance，更清晰
    
    for (int i = 0; i <= n; i++) {
        record[i] = 0;
        distance[i] = INT_MAX;
    }
    
    distance[s] = 0;
    Cdata(s, &M, 0, distance);  // 起点入堆
    
    while (M.size > 0) {
        heapNode cur = popMin(&M);
        if (record[cur.point]) continue;
        record[cur.point] = 1;
        
        int edge_idx = G.Gh[cur.point];
        while (edge_idx != -1) {
            int to = G.nodes[edge_idx].to;
            int w = G.nodes[edge_idx].weight;
            
            //  只调用 Cdata，它内部会更新 distance
            if (!record[to] && cur.data + w < distance[to]) {
                Cdata(to, &M, cur.data + w, distance);
                // ❌ 注意：这里不再手动更新 distance[to]
            }
            
            edge_idx = G.nodes[edge_idx].next;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INT_MAX) {
            printf("INF ");
        } else {
            printf("%d ", distance[i]);
        }
    }
    printf("\n");
    
    // 释放内存
    free(G.nodes);
    free(G.Gh);
    free(M.heaps);
    free(M.index);
    
    return 0;
}