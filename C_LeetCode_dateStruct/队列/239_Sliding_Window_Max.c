/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *res=(int*)malloc(sizeof(int)*(numsSize+1));
    int left=0;
    int right=0;
    int count=0;
    int deque[100001];
    for(int i=0;i<numsSize;i++){
        while(right-left>0&&nums[i]>=nums[deque[right-1]]){
            right--;
        }//维持队头为最大值队列
        deque[right++]=i;
        if(i>=k-1){
            res[count++]=nums[deque[left]];
            if(i-k+1==deque[left])left++;
        }//长度达到要求开始计算
    }
    *returnSize=count;
    return res;
}