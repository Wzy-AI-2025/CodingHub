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
        board[dy]=dx;//合并集合
        (*sets)--;
    }
}
int numSimilarGroups(char** strs, int strsSize) {
    int*board=(int*)malloc(sizeof(int)*strsSize);
    int sets=strsSize;
    for(int i=0;i<strsSize;i++){
        board[i]=i;//初始化并查集
    }
    for(int i=0;i<strsSize-1;i++){
        for(int j=i+1;j<strsSize;j++){
            int differ=0;
            for(int k=0;k<strlen(strs[0]);k++){
                if(strs[i][k]!=strs[j][k])differ++;
            }
            if(differ==0||differ==2)uion(i,j,board,&sets);
        }
    }
    return sets;
}