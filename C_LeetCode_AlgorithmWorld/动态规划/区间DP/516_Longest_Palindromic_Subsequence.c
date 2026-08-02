int f(char* s, int i, int j,int **dp) {
    int ans = 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if (i == j) {
        ans = 1;
    } else if (i == j - 1) {
        ans = s[i] == s[j] ? 2 : 1;
    } else {
        if (s[i] == s[j]) {
            ans = f(s, i + 1, j - 1,dp) + 2;
        } else {
            int l = f(s, i + 1, j,dp);
            int r = f(s, i, j - 1,dp);
            ans= l > r ? l : r;
        }
    }
    dp[i][j]=ans;
    return ans;
}

int longestPalindromeSubseq(char* s) {
    int size = strlen(s);
    int **dp=(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
        dp[i]=(int*)malloc(sizeof(int)*size);
        memset(dp[i],-1,sizeof(int)*size);
    }
    return f(s, 0, size - 1,dp);
}