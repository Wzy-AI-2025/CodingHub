int minSubarray(int* nums, int numsSize, int p) {
    long long allsum=0;
    long long len=numsSize;
    for(int i=0;i<numsSize;i++){
        allsum+=nums[i];
    }
    long long result=allsum%p;
    if(result==0)return 0;
    int hash[p];
    for(int i=0;i<p;i++){
        hash[i]=-2;
    }
    hash[0]=-1;
    long long sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        int target=(sum%p+p-result)%p;
        if(hash[target]!=-2&&i-hash[target]<len)len=i-hash[target];
        hash[sum%p]=i;
    }
    if(len==numsSize)return -1;
    return len;
}