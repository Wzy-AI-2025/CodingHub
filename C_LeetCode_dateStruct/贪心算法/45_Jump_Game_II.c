int jump(int* nums, int numsSize) {
    int start=0;
    int count=0;
    if(numsSize==1)return 0;
    while(start+nums[start]<numsSize-1){
        int maxjump=0;
        int s=0;
        int n=nums[start];
        for(int i=1;i<=n;i++){
            if(nums[start+i]+start+i>maxjump){
            maxjump=nums[start+i]+start+i;
            s=start+i;
           }
        }
        start=s;
        count++;
    }
    return count+1;
}