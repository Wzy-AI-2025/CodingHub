int minOperations(int* nums, int numsSize, int x) {
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    int target=0;
    int len=-1;
    int left=0;
    if(sum<x)return -1;
    for(int right=0;right<numsSize;right++){
        target+=nums[right];
        while(sum-target<x){
            target-=nums[left];
            left++;
        }
        if(sum-target==x){
            if(right-left+1>len)len=right-left+1;
        }
    }
    if(len==-1)return -1;
    return numsSize-len;
}