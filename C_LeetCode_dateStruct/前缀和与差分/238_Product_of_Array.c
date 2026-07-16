/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int right[numsSize+1];
    int left[numsSize+1];
    int sum=1;
    right[0]=1;
    left[0]=1;
    for(int i=0;i<numsSize;i++){
        sum=sum*nums[i];
        left[i+1]=sum;
    }
    sum=1;
    int count=1;
    for(int i=numsSize-1;i>=0;i--){
        sum=sum*nums[i];
        right[count++]=sum;
    }
    int *result=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        result[i]=left[i]*right[numsSize-i-1];
    }
    *returnSize=numsSize;
    return result;
}