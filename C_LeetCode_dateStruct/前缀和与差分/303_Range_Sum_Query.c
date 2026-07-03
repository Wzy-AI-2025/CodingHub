
typedef struct {
    int*piex;
    int size;
} NumArray;
NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray*obj=(NumArray*)malloc(sizeof(NumArray));
    obj->size=numsSize;
    obj->piex=(int*)malloc(sizeof(int)*(numsSize+1));
    obj->piex[0]=0;
    for(int i=1;i<=numsSize;i++){
        obj->piex[i]=obj->piex[i-1]+nums[i-1];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->piex[right+1]-obj->piex[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->piex);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/