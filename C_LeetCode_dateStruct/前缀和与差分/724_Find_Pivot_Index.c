int pivotIndex(int* nums, int numsSize) {
    int result=0;
    for(int i=0;i<numsSize;i++){
        result+=nums[i];
    }
    int len=-1;
    int sum=0;
    for(int i=0;i<numsSize;i++){
        if(sum==(result-sum-nums[i])){
            len=i;
            break;
        } 
        sum+=nums[i];
    }
    return len;
}