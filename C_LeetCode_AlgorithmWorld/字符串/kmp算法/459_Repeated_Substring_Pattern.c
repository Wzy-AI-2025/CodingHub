void initNext(char* s, int* next, int n) {
    next[0] = 0;  // 直接存长度
    int cnt = 0, i = 1;
    while (i < n) {
        if (s[i] == s[cnt]) {
            next[i++] = ++cnt;
        } else if (cnt > 0) {
            cnt = next[cnt - 1];
        } else {
            next[i++] = 0;
        }
    }
}

bool repeatedSubstringPattern(char* s) {
    int n = strlen(s);
    int next[n];
    initNext(s, next, n);
    int len = next[n - 1]; 
    return len > 0 && n % (n - len) == 0;
}