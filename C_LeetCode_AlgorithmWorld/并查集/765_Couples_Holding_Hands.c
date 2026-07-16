int find(int i,int *board){
    if(i==board[i])return board[i];
    return find(board[i],board);
}
void uion(int x,int y,int *board,int *sets){
    int dx=find(x,board);
    int dy=find(y,board);
    if(dx!=dy){
        board[dx]=dy;
        (*sets)--;
    }
}
int minSwapsCouples(int* row, int rowSize) {
    int sets=rowSize/2;
    int *board=(int*)malloc(sizeof(int)*sets);
    for(int i=0;i<sets;i++){
        board[i]=i;
    }
    for(int i=0;i<rowSize-1;i=i+2){
       uion(row[i] / 2, row[i + 1] / 2, board, &sets);
    }
    return rowSize/2-sets;
}