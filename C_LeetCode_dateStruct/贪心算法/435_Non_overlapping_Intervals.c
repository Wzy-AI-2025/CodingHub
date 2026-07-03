int cmp(const void *a,const void *b){
    return (*(int**)a)[1]-(*(int**)b)[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals,intervalsSize,sizeof(int*),cmp);
    int count=1;
    int right=0;
    for(int i=1;i<intervalsSize;i++){
        if(intervals[i][0]>=intervals[right][1]){
            right=i;
            count++;
        }
    }
    return intervalsSize-count;
}