int k;//记录每次探索的次数
void dfs(int**grid,int gridSize,int sSize,int row,int col){
    if(grid[row][col]==0)return;
    grid[row][col]=0;
    k++;
    if(row-1>=0&&grid[row-1][col]==1)dfs(grid,gridSize,sSize,row-1,col);
    if(col-1>=0&&grid[row][col-1]==1)dfs(grid,gridSize,sSize,row,col-1);
    if(row+1<gridSize&&grid[row+1][col]==1)dfs(grid,gridSize,sSize,row+1,col);
    if(col+1<sSize&&grid[row][col+1]==1)dfs(grid,gridSize,sSize,row,col+1);
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int sSize=gridColSize[0];
    int max=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<sSize;j++){
            if(grid[i][j]==1){//发现新大陆
            k=0;
            dfs(grid,gridSize,sSize,i,j);//淹没新大陆
            max=max>k?max:k;
            }
        }
    }
    return max;
}