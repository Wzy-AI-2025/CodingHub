void heapadjust(int *nums,int n,int i){//对i位置节点进行堆调整;
    int left=i*2+1;//左节点 
    int right=i*2+2;//右节点
    int max=i;//记录最大值的位置
    if(left<n&&nums[max]<nums[left])max=left;
    if(right<n&&nums[max]<nums[right])max=right;
    if(max!=i){
        int temp=nums[i];
        nums[i]=nums[max];
        nums[max]=temp;
        heapadjust(nums,n,max);//交换后要检查被交换的子节点是否还符合大顶堆
    }
}
void heapsort(int *nums,int n){
    for(int i=n/2-1;i>=0;i--){
        heapadjust(nums,n,i);//构建大顶堆
    }
    for(int i=n-1;i>0;i--){
        int temp=nums[0];
        nums[0]=nums[i];
        nums[i]=temp;//取出堆顶最大值放在数组末尾
        heapadjust(nums,i,0);//维持剩下的N-1个元素为大顶堆
    }
}
int findKthLargest(int* nums, int numsSize, int k) {
    heapsort(nums,numsSize);
    return nums[numsSize-k];
}