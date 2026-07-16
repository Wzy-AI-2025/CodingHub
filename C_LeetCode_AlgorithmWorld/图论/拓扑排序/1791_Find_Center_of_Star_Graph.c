//度为n-1的点就是中心节点
int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int*degree=(int*)malloc(sizeof(int)*100001);//0小标弃而不用
    memset(degree,0,sizeof(int)*100001);
    int count=0;
    for(int i=0;i<edgesSize;i++){
        if(degree[edges[i][0]]++==0)count++;
        if(degree[edges[i][1]]++==0)count++;
    }
    for(int i=1;i<count+1;i++){
        if(degree[i]==count-1)return i;
    }
    return 0;
}