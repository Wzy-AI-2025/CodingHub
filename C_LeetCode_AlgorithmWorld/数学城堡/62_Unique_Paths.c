int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;  // 用对称性，取较小的 k
    
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }
    return (int)result;
}

int uniquePaths(int m, int n) {
    int r=m+n-2;
    int l=m-1;
    return C(r,l);
}