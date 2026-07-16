/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *res=(int*)malloc(sizeof(int)*temperaturesSize);
    memset(res,0,sizeof(int)*(temperaturesSize));
    int stack[100001]={0};
    stack[0]=0;
    int r=0;
    for(int i=0;i<temperaturesSize;i++){
            while(r>0&&temperatures[stack[r-1]]<temperatures[i]){
                res[stack[r-1]]=i-stack[r-1];
                r--;
            }
            stack[r++]=i;
        }
    *returnSize=temperaturesSize;
    return res;
}