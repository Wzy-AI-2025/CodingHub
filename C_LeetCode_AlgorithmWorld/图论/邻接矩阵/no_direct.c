/*
手动构建无向邻接矩阵:
[1,3]
[1,2]
[2,3]
[2,4]
[4,3]
*/
#include<stdio.h>
int board[5][5]={0};
void creatNode(int i,int j){
    board[i][j]=1;
    board[j][i]=1;
}
int main(){
    creatNode(1,3);
    creatNode(1,2);
    creatNode(2,3);
    creatNode(2,4);
    creatNode(4,3);
    for(int i=1;i<5;i++){
    printf("\n");
    for(int j=1;j<5;j++)
    printf("%d",board[i][j]);
   }
   return 0;
}