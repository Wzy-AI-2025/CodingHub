int longestSubarray(int* nums, int numsSize, int limit) {
    int left=0;
    int maxdeque[numsSize];//维持队头为最大值队列
     int mindeque[numsSize];//维持队头为最小值队列
     int maxlen=0;
    int maxleft=0,minleft=0,maxright=0,minright=0;
    for(int right=0;right<numsSize;right++){
        while(maxright-maxleft>0&&nums[right]>=nums[maxdeque[maxright-1]]){
            maxright--;
        }
        maxdeque[maxright++]=right;
        while(minright-minleft>0&&nums[right]<=nums[mindeque[minright-1]]){
            minright--;
        }
        mindeque[minright++]=right;
        while(nums[maxdeque[maxleft]]-nums[mindeque[minleft]]>limit){
            if(left==maxdeque[maxleft])maxleft++;
            if(left==mindeque[minleft])minleft++;
            left++;
        }
        maxlen=maxlen>right-left+1?maxlen:right-left+1;
    }
    return maxlen;
}