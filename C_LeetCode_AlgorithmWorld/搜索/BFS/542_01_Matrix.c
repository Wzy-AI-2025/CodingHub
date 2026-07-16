/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct {
    int x;
    int y;
 }point;//定义坐标结构体
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize=matSize;
    *returnColumnSizes=(int*)malloc(sizeof(int)*matSize);
    for(int i=0;i<matSize;i++)(*returnColumnSizes)[i]=matColSize[0];
    int**dist=(int**)malloc(sizeof(int*)*matSize);//用来记录到达1的最小步数
    for(int i=0;i<matSize;i++)dist[i]=(int*)malloc(sizeof(int)*matColSize[0]);
    point qenue[matSize*matColSize[0]];//用队列来实现bfs
    int left=0;
    int right=0;
    for(int i=0;i<matSize;i++){
        for(int j=0;j<matColSize[0];j++){
            if(mat[i][j]==0){
            qenue[right++]=(point){i,j};//如果是0,进队列
            dist[i][j]=0;
            }
            else dist[i][j]=-1;
        }
    }
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};//获取坐标四个方向
    while(left<right){//用队列模拟bfs
    point getfront=qenue[left++];//获取队首，并且队首出列
    int x=getfront.x;
    int y=getfront.y;
    for(int i=0;i<4;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0&&y1>=0&&x1<matSize&&y1<matColSize[0]&&dist[x1][y1]==-1){
            dist[x1][y1]=dist[x][y]+1;
            qenue[right++]=(point){x1,y1};//入队
        }
    }
    }
    return dist;
}