/*
图:
[1,3]
[1,2]
[2,3]
[2,4]
[4,3]
链式前向星的实质是使用数组模拟邻接表,即模拟链表
*/
#include <stdio.h>

int edge = 1;//表示第edge条边

//u指向v
void addedge(int u, int v, int* head, int* to, int* next) {
    int cur = head[u];//记录原先的边
    head[u] = edge;//新的边
    next[edge] = cur;//指向原来的边
    to[edge++] = v;//这条边的编号指向的值

    next[edge] = head[v];
    head[v] = edge;
    to[edge++] = u;
}//类似于头插法的样子,


int main() {
    int head[5] = { 0 };//下标表示点,值表示边的编号
    int to[13];//这里一共有6条边,to的下表表示边的编号,值表示指向的点
    int next[13];//下标表示边的编号,值表示这条边指向的下一条边的编号
    addedge(1, 3, head, to, next);
    addedge(1, 2, head, to, next);
    addedge(2, 3, head, to, next);
    addedge(2, 4, head, to, next);
    addedge(4, 3, head, to, next);
    for (int i = 1; i < 5; i++) {
        printf("%d", i);
        int cur = head[i];
        while (cur != 0) {
            printf("->%d", to[cur]);
            cur = next[cur];
        }
        printf("\n");
    }
    return 0;
}