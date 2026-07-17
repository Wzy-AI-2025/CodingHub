#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int find(int i,int *father){
    if(father[i]!=i){
        father[i]=find(father[i],father);
    }
    return father[i];
}//找出i点的父亲,并且扁平化;

int conect(int u,int v,int*father){
    int du=find(u,father);
    int dv=find(v,father);
    if(du==dv)return 0;
    else father[dv]=du;
    return 1;
}//如果合法合并u和v;

int cmp(const void *a, const void *b) {
    int *dx = *(int **)a;  // 解引用一次得到 int*
    int *dy = *(int **)b;
    if (dx[2] > dy[2]) return 1;
    if (dx[2] < dy[2]) return -1;
    return 0;
}

int main(){
    int point_count,edge_count;
    int count=0;
    scanf("%d %d",&point_count,&edge_count);
    int**broad=(int**)malloc(sizeof(int*)*edge_count);
    for(int i=0;i<edge_count;i++){
        broad[i]=(int*)malloc(sizeof(int)*3);
    }
    for(int i=0;i<edge_count;i++){
        scanf("%d %d %d",&broad[i][0],&broad[i][1],&broad[i][2]);
    }
    qsort(broad,edge_count,sizeof(broad[0]) ,cmp);
    int*father=(int*)malloc(sizeof(int)*(point_count+1));
    for(int i=1;i<=point_count;i++){
        father[i]=i;
    }
    int weight=0;
    for(int i=0;i<edge_count;i++){
        if(conect(broad[i][0],broad[i][1],father)){
            count++;
            weight+=broad[i][2];
        }
    }
    if(count==point_count-1)printf("%d\n",weight);
    else printf("orz\n");
    if (edge_count > 0) {
        for (int i = 0; i < edge_count; i++) free(broad[i]);
        free(broad);
    }
    free(father);
    return 0;
}