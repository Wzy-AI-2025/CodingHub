int min(int i, int j) { return i < j ? i : j; }

int f(int* values, int i, int j, int** dp) {
    int ans = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    else if (i == j) {
        ans = 0;
    } else if (i == j - 1) {
        return 0;
    } else {
        for (int m = i + 1; m < j; m++) {
            ans = min(ans, f(values, i, m, dp) + f(values, m, j, dp) +
                               values[i] * values[j] * values[m]);
        }
    }
    dp[i][j] = ans;
    return ans;
}

int minScoreTriangulation(int* values, int valuesSize) {
    int** dp = (int**)malloc(sizeof(int*) * valuesSize);
    for (int i = 0; i < valuesSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * valuesSize);
        memset(dp[i], -1, sizeof(int) * valuesSize);
    }
    return f(values, 0, valuesSize - 1, dp);
}