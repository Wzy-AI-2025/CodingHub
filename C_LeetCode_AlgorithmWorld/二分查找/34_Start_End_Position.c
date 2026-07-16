int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *m=(int *)malloc(sizeof(int)*2);
    m[0]=-1;m[1]=-1;
    *returnSize=2;
    if(numsSize==0)return m;
    int left1=0,right1=numsSize-1;
    int left=0,right=numsSize-1;
    while(left1<=right1){
        int mid=(left1+right1)/2;
        if(nums[mid]>=target)right1=mid-1;
        else left1=mid+1;
    }//如果有，找出开始的位置
    if(left1<numsSize&&nums[left1]==target)m[0]=left1;//验证找的值能不能符合要求
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]<=target)left=mid+1;
        else right=mid-1;
    }//如果有，找出结束位置
    if(right>=0&&nums[right]==target)m[1]=right;//验证找的值能不能符合要求
    return m;
}//这题关键就是通过取等号来找目标的位置