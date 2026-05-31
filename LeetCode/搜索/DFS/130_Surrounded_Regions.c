void dfs(int row,int col,char**board,int boardSize,int sSize){
    if(board[row][col]=='#'||board[row][col]=='X')return;
    board[row][col]='#';//保护该区域，给该位置上锁
    if(row-1>=0&&board[row-1][col]=='O')dfs(row-1,col,board,boardSize,sSize);
    if(col-1>=0&&board[row][col-1]=='O')dfs(row,col-1,board,boardSize,sSize);
    if(row+1<boardSize&&board[row+1][col]=='O')dfs(row+1,col,board,boardSize,sSize);
    if(col+1<sSize&&board[row][col+1]=='O')dfs(row,col+1,board,boardSize,sSize);
}
void solve(char** board, int boardSize, int* boardColSize) {
    int sSize=boardColSize[0];
    //给边界区域上锁
    for(int i=0;i<boardSize;i++){
        if(board[i][0]=='O')dfs(i,0,board,boardSize,sSize);
        if(board[i][sSize-1]=='O')dfs(i,sSize-1,board,boardSize,sSize);
    }
    for(int j=0;j<sSize;j++){
        if(board[0][j]=='O')dfs(0,j,board,boardSize,sSize);
        if(board[boardSize-1][j]=='O')dfs(boardSize-1,j,board,boardSize,sSize);
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<sSize;j++){
            if(board[i][j]=='O')board[i][j]='X';
            if(board[i][j]=='#')board[i][j]='O';
        }
    }//解锁
}