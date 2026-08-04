int min(int i, int j) { return i < j ? i : j; }

int f(char* s, int** dp, int i, int j) {
    int ans = INT_MAX;
    if (dp[i][j] != -1) {
        return dp[i][j];
    } else if (i == j) {
        ans = 1;
    } else if (i == j - 1) {
        if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
            ans = 0;
        else
            ans = 2;
    } else {
        if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
            ans = f(s, dp, i + 1, j - 1);
    }
    for (int k = i; k < j; k++) {
        ans = min(ans, f(s, dp, i, k) + f(s, dp, k + 1, j));
    }
    dp[i][j] = ans;
    return ans;
}

int minAddToMakeValid(char* s) {
    int size = strlen(s);
    int** dp = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        dp[i] = (int*)malloc(sizeof(int) * size);
        memset(dp[i], -1, sizeof(int) * size);
    }
    return f(s, dp, 0, size - 1);
}