/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    int* ia = *(int**)a;
    int* ib = *(int**)b;
    return ia[2] - ib[2]; // 按会议时间升序排序
}

int find(int* map, int i) {
    if (map[i] != i) {
        map[i] = find(map, map[i]); // 压缩路径
    }
    return map[i];
}

void unt(int x, int y, int* map, int* saw) {
    int dx = find(map, x);
    int dy = find(map, y);
    if (dx == dy) return;
    if (saw[dx] == 1)
        map[dy] = dx;
    else
        map[dx] = dy; // 如果有知晓密码的专家,优先作为父亲
}

int* findAllPeople(int n, int** meetings, int meetingsSize,
                   int* meetingsColSize, int firstPerson, int* returnSize) {
    qsort(meetings, meetingsSize, sizeof(meetings[0]), cmp);

    int* saw = (int*)calloc(n, sizeof(int));
    saw[0] = saw[firstPerson] = 1;

    for (int i = 0; i < meetingsSize;) {
        int j = i;
        int time = meetings[i][2];

        // 临时并查集：只处理当前时间的专家
        int* map = (int*)malloc(sizeof(int) * n);
        for (int k = 0; k < n; k++) {
            map[k] = k;
        }
        // 双指针思想,模拟会议不同时间段
        while (j < meetingsSize && meetings[j][2] == time) {
            unt(meetings[j][0], meetings[j][1], map, saw);
            j++;
        }

        // 标记该时间知道秘密的人
        for (int k = i; k < j; k++) {
            if (saw[find(map, meetings[k][0])] == 1) {
                saw[meetings[k][0]] = 1;
            }
            if (saw[find(map, meetings[k][1])] == 1) {
                saw[meetings[k][1]] = 1;
            }
        }

        free(map);
        i = j;
    }

    int* result = (int*)malloc(sizeof(int) * n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (saw[i] == 1) {
            result[s++] = i;
        }
    }
    *returnSize = s;
    free(saw);
    return result;
}