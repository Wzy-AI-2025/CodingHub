/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//k算法
int find(int i,int *father){
    if(i!=father[i])father[i]=find(father[i],father);
    return father[i];
}

void un(int u,int v,int*father){
    int dx=find(u,father);
    int dy=find(v,father);
    if(dx!=dy){
        father[dy]=dx;
    }
}

int cmp(void const*a,void const*b){
    int *x=*(int**)a;
    int *y=*(int**)b;
    return x[2]-y[2];
}

int cmp_record(const void *a, const void *b) {
    int *x = *(int (*)[2])a;  // 解引用得到 int*
    int *y = *(int (*)[2])b;
    return x[1] - y[1];
}

bool* distanceLimitedPathsExist(int n, int** edgeList, int edgeListSize, int* edgeListColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    qsort(edgeList,edgeListSize,sizeof(edgeList[0]),cmp);
    int record[queriesSize][2];
    for(int i=0;i<queriesSize;i++){
        record[i][0]=i;//记录下表;
        record[i][1]=queries[i][2];//记录权值
    }
    int father[n];
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    qsort(record,queriesSize,sizeof(record[0]),cmp_record);
    bool*awner=(bool*)malloc(sizeof(bool)*queriesSize);
    memset(awner,0,sizeof(bool)*queriesSize);
    int l=0;
    for(int i=0;i<queriesSize;i++){
        while(l < edgeListSize&&edgeList[l][2]<record[i][1]){
            un(edgeList[l][0],edgeList[l][1],father);
            l++;
        }
        int u = queries[record[i][0]][0];
        int v = queries[record[i][0]][1];
        if (find(u, father) == find(v, father)) {
           awner[record[i][0]] = 1;
        }
    }
    *returnSize=queriesSize;
    return awner;
}