/*
手动构建有向邻接矩阵:
[1,3]
[3,1]
[1,2]
[2,3]
[2,4]
[4,3]
*/
#include<stdio.h>
int broad[5][5]={0};//数组的0行和0列弃而不用
void creatNode(int i,int j){
   broad[i][j]=1;
}
int main(){
   creatNode(1,3);
   creatNode(3,1);
   creatNode(1,2);
   creatNode(2,3);
   creatNode(2,4);
   creatNode(4,3);
   for(int i=1;i<5;i++){
    printf("\n");
    for(int j=1;j<5;j++)
    printf("%d",broad[i][j]);
   }
   return 0;
}