
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int solve(int *cuts, int i, int j, int left, int right, int **memo) {
    if (i > j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    
    int ans = INT_MAX;
    for (int m = i; m <= j; m++) {
        int cost = (right - left);
        cost += solve(cuts, i, m-1, left, cuts[m], memo);
        cost += solve(cuts, m+1, j, cuts[m], right, memo);
        ans = min(ans, cost);
    }
    memo[i][j] = ans;
    return ans;
}

int minCost(int n, int* cuts, int cutsSize) {
    qsort(cuts, cutsSize, sizeof(int), cmp);
    
    // 创建记忆化数组
    int **memo = (int**)malloc(cutsSize * sizeof(int*));
    for (int i = 0; i < cutsSize; i++) {
        memo[i] = (int*)malloc(cutsSize * sizeof(int));
        for (int j = 0; j < cutsSize; j++) {
            memo[i][j] = -1;
        }
    }
    
    int result = solve(cuts, 0, cutsSize-1, 0, n, memo);
    
    // 释放内存
    for (int i = 0; i < cutsSize; i++) {
        free(memo[i]);
    }
    free(memo);
    
    return result;
}