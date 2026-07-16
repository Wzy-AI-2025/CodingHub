typedef struct Edge {
    int val;
    struct Edge* next;
} Edge; // 定义点

typedef struct ArEdge {
    int date; // 废数据
    Edge* firsth;
} ArEdge; // 虚拟头

typedef struct Graph {
    int date; // 废数据
    ArEdge* Gp;
} Graph; // 图

void initGraph(int numCourses, Graph* G) {
    G->Gp = (ArEdge*)malloc(sizeof(ArEdge) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        G->Gp[i].firsth = NULL;
    }
} // 初始化图

void addNode(int u, int v, Graph* G) { // u->v
    Edge* cur = (Edge*)malloc(sizeof(Edge));
    cur->val = v;
    cur->next = G->Gp[u].firsth;
    G->Gp[u].firsth = cur;
} // 添加点

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize) {
    Graph G;
    initGraph(numCourses, &G);
    int* in_degree = (int*)malloc(sizeof(int) * numCourses); // 入度表
    memset(in_degree, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        addNode(prerequisites[i][1], prerequisites[i][0], &G);
        in_degree[prerequisites[i][0]]++;
    } // 建图
    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int left = 0, r = 0;
    for (int i = 0; i < numCourses; i++) {
        if (in_degree[i] == 0) {
            queue[r++] = i;
        }
    }
    while (left < r) {
        int cur = queue[left++];
        Edge* dy = G.Gp[cur].firsth;
        while (dy != NULL) {
            int val = dy->val;
            in_degree[val]--;
            if (in_degree[val] == 0)
                queue[r++] = val;
            dy = dy->next;
        }
    }
    free(in_degree);
    free(queue);
    return r == numCourses;
}