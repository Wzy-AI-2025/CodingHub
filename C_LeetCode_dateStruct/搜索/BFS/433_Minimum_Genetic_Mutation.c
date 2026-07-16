int check(char* a, char* b) {
    int differ = 0;
    for (int i = 0; i < 8; i++) {
        if (a[i] != b[i])
            differ++;
    }
    if (differ == 0)
        return 0;
    if (differ == 1)
        return 1;
    return -1;
}
typedef struct {
    int n;    // 单词索引
    int step; // 转换次数；
} point;
int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    if (check(startGene, endGene) == 0)
        return 0;
    int* record = (int*)malloc(sizeof(int) * bankSize);
    point* dneue = (point*)malloc(sizeof(point) * (bankSize + 1));
    for (int i = 0; i < bankSize; i++) {
        if (check(startGene, bank[i]) == 0)
            record[i] = 1;
        else
            record[i] = 0;
    }
    int left = 0;
    int right = 0;
    dneue[right].n = -1;
    dneue[right++].step = 0;
    while (left < right) {
        point cur = dneue[left];
        if (cur.n != -1 && check(bank[cur.n], endGene) == 0)
            return cur.step;
        for (int i = 0; i < bankSize; i++) {
            if (cur.n == -1) {
                if (check(startGene, bank[i]) == 1 && record[i] == 0) {
                    dneue[right].n = i;
                    dneue[right++].step = cur.step + 1;
                    record[i] = 1;
                }
            } else {
                if (check(bank[cur.n], bank[i]) == 1 && record[i] == 0) {
                    dneue[right].n = i;
                    dneue[right++].step = cur.step + 1;
                    record[i] = 1;
                }
            }
        }
        left++;
    }
    return -1;
}