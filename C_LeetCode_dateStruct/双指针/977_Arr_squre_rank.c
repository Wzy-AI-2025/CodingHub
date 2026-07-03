int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *result=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    int k=numsSize-1;
    int left=0;
    int right=numsSize-1;
    while(left<=right){
    if(nums[right]*nums[right]>nums[left]*nums[left]){
        result[k--]=nums[right]*nums[right];
        right--;
    }
    else{
        result[k--]=nums[left]*nums[left];
        left++;
    }
 }
    return result;
}//这题用left接收负数最小值，right接收最右端，因为这是有序数组，平方后的最大值肯定是从数组两端出现的......