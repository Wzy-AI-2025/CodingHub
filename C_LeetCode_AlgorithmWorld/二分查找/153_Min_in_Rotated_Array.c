int findMin(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    
    while(left<right){
    int mid=(left+right)/2;
    if(mid>0&&nums[mid]<nums[mid-1])return nums[mid];
    if(nums[mid]>nums[right])left=mid+1;
    if(nums[mid]<=nums[right]) right=mid-1;
    }
    return nums[left];
}