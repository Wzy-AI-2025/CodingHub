int max(int i,int j){
    return i>j?i:j;
}

int f(int *nums,int i,int j,int**dp){
    if(i<j&&dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(i>j){
        ans=0;
    }
    else if(i==j){
        ans=nums[i];
    }
    else {
    for(int m=i;m<=j;m++){
        ans=max(ans,nums[m]+f(nums,i,m-2,dp)+f(nums,m+2,j,dp));
    }
    }
    if(i<j)dp[i][j]=ans;
    return ans;
}

int rob(int* nums, int numsSize) {
    if(numsSize==1)return nums[0];
    int**dp=(int**)malloc(sizeof(int*)*numsSize);
    for(int i=0;i<numsSize;i++){
        dp[i]=(int*)malloc(sizeof(int)*numsSize);
        memset(dp[i],-1,sizeof(int)*numsSize);
    }
    return max(f(nums,1,numsSize-1,dp),f(nums,0,numsSize-2,dp));
}