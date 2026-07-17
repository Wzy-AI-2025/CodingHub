/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node{
    int val;
    struct Node*next;
}Node;

typedef struct ArNode{
    int date;
    Node *firsth;
}ArNode;

typedef struct Graph{
    int date;
    ArNode*Gp;
}Graph;

void initGraph(int count,Graph*G){
    G->Gp=(ArNode*)malloc(sizeof(ArNode)*(count));
    for(int i=0;i<count;i++){
        G->Gp[i].firsth=NULL;
    }
}

void addNode(int u,int v,Graph*G){
    Node*cur=(Node*)malloc(sizeof(Node));
    cur->val=v;
    cur->next=G->Gp[u].firsth;
    G->Gp[u].firsth=cur;
}

int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize) {
    Graph G;
    initGraph(quietSize,&G);
    int *degree=(int*)malloc(sizeof(int)*quietSize);
    memset(degree,0,sizeof(int)*quietSize);
    for(int i=0;i<richerSize;i++){
        addNode(richer[i][0],richer[i][1],&G);
        degree[richer[i][1]]++;
    }
    int*messege=(int*)malloc(sizeof(int)*quietSize);
    for(int i=0;i<quietSize;i++){
        messege[i]=i;
    }
    *returnSize=quietSize;
    int*qeueu=(int*)malloc(sizeof(int)*(quietSize));
    int l=0,r=0;
    for(int i=0;i<quietSize;i++){
        if(degree[i]==0)qeueu[r++]=i;
    }
    while(l<r){
        int index=qeueu[l++];
        Node*cur=G.Gp[index].firsth;
        while(cur!=NULL){
            int val=cur->val;
            if(--degree[val]==0)qeueu[r++]=val;
            if(quiet[messege[index]]<=quiet[messege[val]])messege[val]=messege[index];
            cur=cur->next;
        }
    }
    return messege;
}