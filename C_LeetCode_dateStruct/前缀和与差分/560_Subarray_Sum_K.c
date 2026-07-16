int subarraySum(int* nums, int numsSize, int k) {
    int*map=(int *)malloc(sizeof(int)*200000001);
    memset(map,0,sizeof(map));
    map[10000000]=1;
    int sum=0;
    int count=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        int target=sum-k;
        count+=map[10000000+target];
        map[10000000+sum]++;
    }
    return count;
}