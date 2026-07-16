int find(int *board,int i){
    if(board[i]!=i){
        board[i]=find(board,board[i]);//压缩路径
    }
    return board[i];
}
void uion(int x,int y,int *board,int *sets){
    int dx=find(board,x);
    int dy=find(board,y);
    if(dx!=dy){
        board[dy]=dx;
        (*sets)--;
    }
}
int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    int *board=(int*)malloc(sizeof(int)*stonesSize);
    for(int i=0;i<stonesSize;i++){
        board[i]=i;//初始化并查集
    }
    int sets=stonesSize;
    int rowfirst[10001];
    int colfirst[10001];
    memset(rowfirst,-1,sizeof(rowfirst));
    memset(colfirst,-1,sizeof(colfirst));
    for(int i=0;i<stonesSize;i++){
        int row=stones[i][0];
        int col=stones[i][1];
        if(rowfirst[row]==-1)rowfirst[row]=i;
        else uion(rowfirst[row],i,board,&sets);
        if(colfirst[col]==-1)colfirst[col]=i;
        else uion(colfirst[col],i,board,&sets);
    }
    return stonesSize-sets;
}