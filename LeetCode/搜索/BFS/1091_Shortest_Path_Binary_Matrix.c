typedef struct{
    int x;
    int y;
}point;
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    if(grid[0][0]==1)return -1;
    int **dist=(int**)malloc(sizeof(int*)*gridSize);
    for(int i=0;i<gridSize;i++){
        dist[i]=(int*)malloc(sizeof(int)*gridColSize[0]);
    }
    point qneue[gridSize*gridColSize[0]];
    int left=0;
    int right=0;
    qneue[right++]=(point){0,0};
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j]==1)dist[i][j]=1;
           else dist[i][j]=-1;
        }
    }
    if(dist[gridSize-1][gridColSize[0]-1]==1)return-1;
    dist[0][0]=1;
    int dx[4]={0,-1,-1,1};
    int dy[4]={1,0,1,1};
    while(left<right){
        point cur=qneue[left++];
        int x=cur.x;
        int y=cur.y;
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>=0&&y1>=0&&x1<gridSize&&y1<gridColSize[0]&&dist[x1][y1]==-1){
                dist[x1][y1]=dist[x][y]+1;
                qneue[right++]=(point){x1,y1};
            }
            x1=x-dx[i];
            y1=y-dy[i];
            if(x1>=0&&y1>=0&&x1<gridSize&&y1<gridColSize[0]&&dist[x1][y1]==-1){
                dist[x1][y1]=dist[x][y]+1;
                qneue[right++]=(point){x1,y1};
            }
        }
    }
    return dist[gridSize-1][gridColSize[0]-1];
}