bool canJump(int* nums, int numsSize) {
    int maxjump=0;
    for(int i=0;i<numsSize;i++){
        if(i>maxjump)return 0;
        else maxjump=maxjump>(i+nums[i])?maxjump:(i+nums[i]);
    }
    return 1;
}