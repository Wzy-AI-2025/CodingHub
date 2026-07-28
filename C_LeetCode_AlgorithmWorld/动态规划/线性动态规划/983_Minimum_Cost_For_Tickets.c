int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int dp[daysSize+1];//表示到第i个任务的最小价钱
    for(int i=0;i<daysSize+1;i++){
        dp[i]=1000000;
    }
    int date[3]={1,7,30};
    dp[0]=0;
    for(int i=0;i<daysSize;i++){
        for(int k=0;k<costsSize;k++){
            int cur=days[i]-date[k];
            if(cur<=0&&dp[i+1]>dp[0]+costs[k])dp[i+1]=dp[0]+costs[k];//越界情况
            else{
                int j=i;
                while(j>=0&&cur<days[j]){
                    j--;
                }
                if(dp[i+1]>dp[j+1]+costs[k])dp[i+1]=dp[j+1]+costs[k];
            }
        }
    }
    return dp[daysSize];
}