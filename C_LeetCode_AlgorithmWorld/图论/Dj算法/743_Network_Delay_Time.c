#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cnt = 0;

// 图结构
typedef struct Edge {
    int to;
    int next;
    int weight;
} Edge;

typedef struct Graph {
    int *Gh;
    Edge *edge;
} Graph;

void initGraph(int point, int count, Graph *G) {
    G->Gh = (int*)malloc(sizeof(int) * (point + 1));
    memset(G->Gh, -1, sizeof(int) * (point + 1));
    G->edge = (Edge*)malloc(sizeof(Edge) * count);
}

void addNode(int u, int v, int val, Graph *G) {
    G->edge[cnt].to = v;
    G->edge[cnt].next = G->Gh[u];
    G->edge[cnt].weight = val;
    G->Gh[u] = cnt;
    cnt++;
}

// 堆结构
typedef struct heapNode {
    int point;
    int val;
} heapNode;

typedef struct Minheap {
    heapNode *nodes;
    int size;
    int capacity;
    int *index;
} Minheap;

void initMinheap(int n, int count, Minheap *M) {
    M->size = 0;
    M->capacity = count;
    M->nodes = (heapNode*)malloc(sizeof(heapNode) * count);
    M->index = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        M->index[i] = -1;
    }
}

void swap(int i, int j, Minheap *M) {
    heapNode temp = M->nodes[i];
    M->nodes[i] = M->nodes[j];
    M->nodes[j] = temp;
    M->index[M->nodes[i].point] = i;
    M->index[M->nodes[j].point] = j;
}

void up(int i, Minheap *M) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (M->nodes[i].val < M->nodes[p].val) {
            swap(i, p, M);
            i = p;
        } else {
            break;
        }
    }
}

void down(int i, Minheap *M) {
    int min = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < M->size && M->nodes[left].val < M->nodes[min].val) min = left;
    if (right < M->size && M->nodes[right].val < M->nodes[min].val) min = right;
    if (min != i) {
        swap(i, min, M);
        down(min, M);
    }
}

void addheap(int point, int weight, int *distance, Minheap *M) {
    if (M->index[point] != -1) {
        // 节点已在堆中
        int cur = M->index[point];
        if (weight < M->nodes[cur].val) {
            M->nodes[cur].val = weight;
            distance[point] = weight;  // 同步更新距离
            up(cur, M);
        }
        return;
    }
    
    // 新节点入堆
    M->nodes[M->size].point = point;
    M->nodes[M->size].val = weight;
    M->index[point] = M->size;
    M->size++;
    up(M->size - 1, M);
}

heapNode pop_min(Minheap *M) {
    heapNode cur = M->nodes[0];
    M->index[cur.point] = -1;
    M->nodes[0] = M->nodes[--(M->size)];
    if (M->size > 0) {
        M->index[M->nodes[0].point] = 0;
    }
    down(0, M);
    return cur;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    if (timesSize == 0) return -1;
    
    cnt = 0;
    
    // 建图
    Graph G;
    initGraph(n, timesSize, &G);
    for (int i = 0; i < timesSize; i++) {
        addNode(times[i][0], times[i][1], times[i][2], &G);
    }
    
    // 初始化距离数组
    int *distance = (int*)malloc(sizeof(int) * (n + 1));
    int *visited = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[k] = 0;
    
    // 建堆
    Minheap M;
    initMinheap(n, timesSize * 2, &M);
    addheap(k, 0, distance, &M);
    
    // Dijkstra
    while (M.size > 0) {
        heapNode cur = pop_min(&M);
        int u = cur.point;
        int dist_u = cur.val;
        
        if (visited[u]) continue;
        visited[u] = 1;
        
        // 遍历邻接边
        int i = G.Gh[u];
        while (i != -1) {
            int v = G.edge[i].to;
            int w = G.edge[i].weight;
            
            if (!visited[v] && dist_u + w < distance[v]) {
                distance[v] = dist_u + w;
                addheap(v, distance[v], distance, &M);
            }
            i = G.edge[i].next;
        }
    }
    
    // 计算结果
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INT_MAX) {
            // 释放内存
            free(G.Gh);
            free(G.edge);
            free(distance);
            free(visited);
            free(M.nodes);
            free(M.index);
            return -1;
        }
        if (distance[i] > maxTime) {
            maxTime = distance[i];
        }
    }
    
    // 释放内存
    free(G.Gh);
    free(G.edge);
    free(distance);
    free(visited);
    free(M.nodes);
    free(M.index);
    
    return maxTime;
}