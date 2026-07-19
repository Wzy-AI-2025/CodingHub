#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int find(int i, int *father) {
    if (i != father[i])
        father[i] = find(father[i], father);
    return father[i];
}

int emger(int u, int v, int *father) {
    int du = find(u, father);
    int dv = find(v, father);
    if (du == dv) return 0;
    father[dv] = du;
    return 1;
}

int cmp(const void *a, const void *b) {
    Edge *x = (Edge *)a;
    Edge *y = (Edge *)b;
    if (x->w > y->w) return 1;
    if (x->w < y->w) return -1;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = (Edge *)malloc(sizeof(Edge) * m);
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int *father = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) father[i] = i;

    qsort(edges, m, sizeof(Edge), cmp);

    int cnt = 0, max = 0;
    for (int i = 0; i < m; i++) {
        if (emger(edges[i].u, edges[i].v, father)) {
            cnt++;
            max = edges[i].w;
        }
    }

    printf("%d %d\n", cnt, max);

    free(edges);
    free(father);
    return 0;
}