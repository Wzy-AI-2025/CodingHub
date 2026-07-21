#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用邻接表吧
typedef struct Node{
    int val;
    struct Node *next;
}Node;//边

typedef struct ArNode{
    int date;//废数据
    struct Node *firsth;
}ArNode;//虚拟头

typedef struct Graph{
    int date;//废数据
    ArNode*Gp;
}Graph;//图结构

void initGraph(Graph *G,int number){
    G->Gp=(ArNode*)malloc(sizeof(ArNode)*(number+1));
    for(int i=0;i<=number;i++){
        G->Gp[i].firsth=NULL;
    }
}//初始化图结构,0下标弃而不用

void addNode(int u, int v, Graph*G){  // 修复参数类型：in → int
    Node*cur=(Node*)malloc(sizeof(Node));
    cur->val=v;
    cur->next=G->Gp[u].firsth;
    G->Gp[u].firsth=cur;
}//添加点

// 小根堆下滤（操作 int 数组）
void heap_down(int* heap, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;

    if (left < n && heap[left] < heap[min])
        min = left;
    if (right < n && heap[right] < heap[min])
        min = right;

    if (min != i) {
        int temp = heap[i];
        heap[i] = heap[min];
        heap[min] = temp;
        heap_down(heap, n, min);
    }
}

// 堆大小
int heap_size;

// 弹出堆顶（最小值）
int heap_pop(int* heap) {
    int top = heap[0];
    heap[0] = heap[--heap_size]; // 末尾移到堆顶
    if (heap_size > 0) {
        heap_down(heap, heap_size, 0);
    }
    return top;
}

// 插入元素到堆
void heap_push(int* heap, int val) {
    heap[heap_size] = val;
    int i = heap_size;
    heap_size++;
    // 上滤（可选，但为了效率建议加）
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}
//
int main(){
    int number, edgeCount;
    int u, v;
    scanf("%d %d", &number, &edgeCount);
    Graph G;
    initGraph(&G, number);
    int *degree = (int*)malloc(sizeof(int) * (number + 1));
    memset(degree, 0, sizeof(int) * (number + 1));

    for(int i = 0; i < edgeCount; i++){
        scanf("%d %d", &u, &v);
        addNode(u, v, &G);
        degree[v]++;
    }

    // 堆初始化
    int *heap = (int*)malloc(sizeof(int) * (number + 1));
    heap_size = 0;

    // 结果数组
    int *result = (int*)malloc(sizeof(int) * number);
    int res_index = 0;

    // 将所有入度为0的点加入堆
    for(int i = 1; i <= number; i++){
        if(degree[i] == 0) {
            heap_push(heap, i);
        }
    }

    // 拓扑排序主循环
    while (heap_size > 0) {
        int cur = heap_pop(heap);
        result[res_index++] = cur;

        // 遍历邻接点
        Node* p = G.Gp[cur].firsth;
        while (p != NULL) {
            int neighbor = p->val;
            degree[neighbor]--;
            if (degree[neighbor] == 0) {
                heap_push(heap, neighbor);
            }
            p = p->next;
        }
    }

    // 输出结果
    for (int i = 0; i < res_index; i++) {
        if (i > 0) printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");

    free(degree);
    free(heap);
    free(result);
    // 邻接表未释放，但题目小，可接受

    return 0;
}