int removeElement(int* nums, int numsSize, int val) {
    int left=0;//从左边开始寻找目标值
    int right=numsSize-1;//用来存放目标值的地方
    while(left<=right){
    if(nums[left]==val&&nums[right]!=val){
        nums[left]=nums[right];
        nums[right]=val;
    }//如果left找到目标值并且right不是目标值就交换两者位置
    if(nums[left]!=val)left++;
    if(nums[right]==val)right--;
    }
    return right+1;
}