//运用拓扑排序的入度和出度思想
int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int *in_degree=(int*)malloc(sizeof(int)*(n+1));
    int *out_degree=(int*)malloc(sizeof(int)*(n+1));//下标0弃而不用
    memset(in_degree,0,sizeof(int)*(n+1));
    memset(out_degree,0,sizeof(int)*(n+1));
    for(int i=0;i<trustSize;i++){
        in_degree[trust[i][1]]++;
        out_degree[trust[i][0]]++;
    }
    for(int i=1;i<n+1;i++){
        if(in_degree[i]==n-1&&out_degree[i]==0)return i;
    }
    return -1;
}