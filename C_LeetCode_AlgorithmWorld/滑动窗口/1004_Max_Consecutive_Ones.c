int longestOnes(int* nums, int numsSize, int k) {
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0)count++;
    }
    if(count<=k)return numsSize;
    int left=0;
    int len=0;
    for(int right=0;right<numsSize;right++){
        if(nums[right]==0)k--;
        if(k==0){
            if(right-left+1>len){
                len=right-left+1;
            }
        }
        if(k<0){
            while(nums[left]==1){
                left++;
            }
            left++;
            k++;
        }
    }
    return len;
}