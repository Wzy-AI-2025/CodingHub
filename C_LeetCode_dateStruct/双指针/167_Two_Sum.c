int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left=0;
    int right=numbersSize-1;
    *returnSize=2;
    int*result=(int*)malloc(sizeof(int)*2);
    while(left<right){
    if(numbers[left]+numbers[right]==target){
        result[0]=left+1;
        result[1]=right+1;
        break;
    }
    else if(numbers[left]+numbers[right]>target){
        right--;
    }
    else{
        left++;
    }
    }
    return result;
}//利用left获取数组左边索引，right获取数组右索引;
//题目假设只有唯一答案;
//如果nums[left]+nums[right]>target则right--.因为right不可能是答案了,只能下一个;
//同理nums[left]+nums[right]<target,left++;