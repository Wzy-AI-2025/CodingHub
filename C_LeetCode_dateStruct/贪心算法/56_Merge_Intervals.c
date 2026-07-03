/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void*a,const void *b){
    return (*(int **)a)[0]-(*(int**)b)[0];
 }
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals,intervalsSize,sizeof(int*),cmp);
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count=0;
    result[0] = (int*)malloc(2 * sizeof(int));
    int left=intervals[0][0];
    int right=intervals[0][1];
    for(int i=0;i<intervalsSize;i++){
        if(intervals[i][0]<=right){
            right=right>=intervals[i][1]?right:intervals[i][1];
        }
        else{
            left=intervals[i][0];
            right=intervals[i][1];
            count++;
            result[count] = (int*)malloc(2 * sizeof(int));
        }
        *returnSize = count+1;
        result[count][0]=left;
        result[count][1]=right;
        (*returnColumnSizes)[count] = 2;
    }
    return result;
}