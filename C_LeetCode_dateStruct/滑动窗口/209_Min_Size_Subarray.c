int minSubArrayLen(int target, int* nums, int numsSize) {
    int left=0;
    int right=0;
    int sum=0;
    int length=numsSize+1;
    for(right=0;right<numsSize;right++){
        sum+=nums[right];
        while(sum-nums[left]>=target)
        {
            sum-=nums[left];
            left++;
        }
        if(sum>=target&&right-left+1<length)length=right-left+1;
    }
    if(length==numsSize+1)return 0;
    return length;
}