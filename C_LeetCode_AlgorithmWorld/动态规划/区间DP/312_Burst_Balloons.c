
int f(int *record,int i,int j,int **dp){
    if(i==j-1)return 0;
    if(dp[i][j]!=0)return dp[i][j];
    for(int m=i+1;m<j;m++){
        int value=record[m]*record[i]*record[j]+f(record,i,m,dp)+f(record,m,j,dp);
        if(value>dp[i][j])dp[i][j]=value;
    }//假设m处为最后戳破的气球
    return dp[i][j];
}

int maxCoins(int* nums, int numsSize) {
    int record[numsSize+2];
    for(int i=0;i<numsSize;i++){
        record[i+1]=nums[i];
    }
    record[0]=1;
    record[numsSize+1]=1;//对原数组进行扩容方便后续操作
    int **dp = (int**)malloc((numsSize + 2) * sizeof(int*));
    for (int i = 0; i < numsSize + 2; i++) {
        dp[i] = (int*)calloc(numsSize + 2, sizeof(int));
    }
    //dp[i][j]表示当前区间可获得的最大数量
    return f(record, 0, numsSize+1, dp);
}