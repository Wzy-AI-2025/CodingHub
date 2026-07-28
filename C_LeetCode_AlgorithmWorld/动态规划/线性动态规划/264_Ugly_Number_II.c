int nthUglyNumber(int n) {
    int dp[n+1];
    dp[1]=1;
    int r2=1,r3=1,r5=1;
    for(int i=1;i<n;i++){
        int a=dp[r2]*2;
        int b=dp[r3]*3;
        int c=dp[r5]*5;
        int cur=(a<b?a:b)<c?(a<b?a:b):c;
        if(cur==a)r2++;
        if(cur==b)r3++;
        if(cur==c)r5++;
        dp[i+1]=cur;
    }
    return dp[n];
}