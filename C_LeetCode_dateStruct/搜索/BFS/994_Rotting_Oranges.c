void contract(int row,int col,int**grid,int gridSize,int n,int*right,int**deque){//感染橘子
if(row-1>=0&&grid[row-1][col]==1){
grid[row-1][col]=2;
deque[*right][0]=row-1;
deque[(*right)++][1]=col;
}
if(col-1>=0&&grid[row][col-1]==1){
grid[row][col-1]=2;
deque[*right][0]=row;
deque[(*right)++][1]=col-1;
}
if(row+1<gridSize&&grid[row+1][col]==1){
grid[row+1][col]=2;
deque[*right][0]=row+1;
deque[(*right)++][1]=col;
}
if(col+1<n&&grid[row][col+1]==1){
grid[row][col+1]=2;
deque[*right][0]=row;
deque[(*right)++][1]=col+1;
}
return;
}
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int n=gridColSize[0];
    //这题我用队列实现bfs
    int **deque=(int**)malloc(sizeof(int*)*gridSize*n);
    for(int i=0;i<gridSize*n;i++){
         deque[i] = (int*)malloc(sizeof(int) * 2);
    }
    int left=0;
    int right=0;
    int count=0;//记录新鲜橘子数
    int minute=-1;//记录扩散时间数
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
            deque[right][0]=i;
            deque[right++][1]=j;
            }
            if(grid[i][j]==1)count++;
        }
    }
    if(count==0)return 0;//如果全是没有新鲜橘子提前结束，因为题目存在没有橘子的情况
    while(right>left){
            int size=right-left;
            for(int i=0;i<size;i++){
            int row=deque[left][0];
            int col=deque[left++][1];
            contract(row,col,grid,gridSize,n,&right,deque);
            }
            minute++;
    }
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)return -1;
        }
    }
    return minute;
}