//邻接矩阵法
int Check(int**board,int i,int n){//检验i号是不是小镇法官
for(int j=1;j<n+1;j++){
    if(j!=i){//
        if(board[j][i]==0)return 0;//所有人要信任法官
        if(board[i][j]==1)return 0;//法官不信任何人
    }
}
return i;
}
int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int**board=(int**)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<n+1;i++){//0下标都弃而不用
        board[i]=(int*)malloc(sizeof(int)*(n+1));
        memset(board[i],0,sizeof(int)*(n+1));
    }
    for(int i=0;i<trustSize;i++){
        board[trust[i][0]][trust[i][1]]=1;
    }
    for(int i=1;i<n+1;i++){
        if(Check(board,i,n))return i;
    }
    return -1;
}