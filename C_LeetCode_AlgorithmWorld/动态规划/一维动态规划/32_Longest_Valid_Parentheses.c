int longestValidParentheses(char* s) {
    int size = strlen(s);
    if(size==0)return 0;
    int dp[size];
    for (int i = 0; i < size; i++) {
        dp[i] = 0;
    } // 表示以s[i]结尾向左延申的最大长度
    int max = 0;
    for (int i = 1; i < size; i++) {
        if (s[i] == ')') {
            int p = i - 1 - dp[i - 1];
            if (p >= 0 && s[p] == '(') {
                dp[i] = dp[i - 1] + 2 + (p - 1 >= 0 ? dp[p - 1] : 0);
            }
        }
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}