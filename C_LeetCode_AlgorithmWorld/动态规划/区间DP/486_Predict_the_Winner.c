int min(int a,int b){
    return a<b?a:b;
}

int f(int *nums,int i,int j){
    if(i==j)return nums[i];
    if(i==j-1)return nums[i]>nums[j]?nums[i]:nums[j];
    int l=nums[i]+min(f(nums,i+2,j),f(nums,i+1,j-1));
    int r=nums[j]+min(f(nums,i,j-2),f(nums,i+1,j-1));
    return l>r?l:r;
    
}//轮到玩家1了

bool predictTheWinner(int* nums, int numsSize) {
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    return f(nums,0,numsSize-1)>=sum-f(nums,0,numsSize-1)?1:0;
}