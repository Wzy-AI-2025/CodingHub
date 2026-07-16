int cmp(const void*a,const void*b){
    if((*(int**)a)[1]==((*(int**)b))[1])return 0;
    return (*(int**)a)[1]>(*(int**)b)[1]?1:-1;
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    int count=1;
    int right=0;
    qsort(points,pointsSize,sizeof(int*),cmp);
    for(int i=1;i<pointsSize;i++){
        if(points[i][0]>points[right][1]){
            right=i;count++;
        }
    }
    return count;
}