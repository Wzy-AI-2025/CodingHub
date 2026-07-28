int numDecodings(char* s) {
    int size = strlen(s);
    if (size == 0 || s[0] == '0') return 0;
    
    int dp[size + 1];  // dp[i] 表示前 i 个字符的解码方式
    dp[0] = 1;         // 空字符串
    dp[1] = 1;         // 第一个字符
    
    for (int i = 2; i <= size; i++) {
        dp[i] = 0;
        
        // 单个字符解码
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        
        // 两个字符组合解码
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[size];
}