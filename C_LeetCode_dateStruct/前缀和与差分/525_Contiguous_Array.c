int findMaxLength(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0)nums[i]=-1;
    }
    int sum=nums[0];
    int len=0;
    int*map=(int*)malloc(sizeof(int)*200001);
    for(int i=0;i<200001;i++){
        map[i]=-2;
    }
    map[100000]=-1;
    map[100000+sum]=0;
    for(int i=1;i<numsSize;i++){
        sum+=nums[i];
        int target=sum;
        if(map[sum+100000]==-2)map[sum+100000]=i;
        if(map[target+100000]!=-2&&i-map[target+100000]>len)len=i-map[target+100000];
    }
    free(map);
    return len;
}