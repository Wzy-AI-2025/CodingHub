int shortestSubarray(int* nums, int numsSize, int k) {
    int minlen=numsSize+1;
    long long record[numsSize+1];//储存前i个数据之和,不要忘记开long long
    record[0]=0;
    long long sum=0;//不要忘记开long long
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        record[i+1]=sum;
    }
    int deque[100001];//用队列维持一个小->大的数据
    int left=0;
    int right=0;
    for(int i=0;i<=numsSize;i++){
        while(right-left>0&&record[i]<=record[deque[right-1]]){
            right--;
        }//维持队列的基本结构，同时也逐渐排除前面可能性
        deque[right++]=i;
        while(right-left>0&&record[deque[right-1]]-record[deque[left]]>=k){
            minlen=deque[right-1]-deque[left]<minlen?deque[right-1]-deque[left]:minlen;
            left++;
        }//逐渐排除存在的可能性
    }
    return minlen==numsSize+1?-1:minlen;
}