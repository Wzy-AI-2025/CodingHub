#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int val;
    struct Node*next;
}Node;

typedef struct ArNode{
    int date;
    struct Node*firsth;
}ArNode;

typedef struct Graph{
    int date;
    ArNode*Gp;
}Graph;

void init(int count,Graph*G){
    G->Gp=(ArNode*)malloc(sizeof(ArNode)*(count+1));
    for(int i=0;i<=count;i++){
        G->Gp[i].firsth=NULL;
    }
}

void addNode(int u,int v,Graph*G){
    Node*cur=(Node*)malloc(sizeof(Node));
    cur->val=v;
    cur->next=G->Gp[u].firsth;
    G->Gp[u].firsth=cur;
}

int main(){
    int count,n;
    scanf("%d %d",&count,&n);
    int *in_degree=(int*)malloc(sizeof(int)*(count+1));
    int *out_degree=(int*)malloc(sizeof(int)*(count+1));
    memset(in_degree,0,sizeof(int)*(count+1));
    memset(out_degree,0,sizeof(int)*(count+1));
    int u,v;
    Graph G;
    init(count,&G);
    for(int i=0;i<n;i++){
        scanf("%d %d",&u,&v);
        addNode(u,v,&G);
        in_degree[v]++;
        out_degree[u]++;
    }
    int*qeueu=(int*)malloc(sizeof(int)*(count+1));
    long long*messege=(long long*)malloc(sizeof(long long)*(count+1));
    memset(messege,0,sizeof(long long)*(count+1));
    int left=0,r=0;
    for(int i=1;i<=count;i++){
        if(in_degree[i]==0){
            qeueu[r++]=i;
            messege[i]=1;
        }
    }
    while(left<r){
        int index=qeueu[left++];
        Node*cur=G.Gp[index].firsth;
        while(cur!=NULL){
            in_degree[cur->val]--;
            if(in_degree[cur->val]==0)qeueu[r++]=cur->val;
            messege[cur->val]+=messege[index];
            messege[cur->val]%=80112002;
            cur=cur->next;
        }
    }
    int result=0;
    for(int i=1;i<=count;i++){
        if(out_degree[i]==0)result+=messege[i];
        result%=80112002 ;
    }
    printf("%d",result);
    return 0;
}