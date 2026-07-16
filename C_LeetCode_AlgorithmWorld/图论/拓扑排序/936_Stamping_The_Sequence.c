/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node{
    int val;
    struct Node*next;
}Node;

typedef struct ArNode{
    int date;
    Node*firsth;
}ArNode;

typedef struct Graph{
    int date;
    ArNode*Gp;
}Graph;

void addNode(int u,int v,Graph*G){
    Node*cur=(Node*)malloc(sizeof(Node));
    cur->val=v;
    cur->next=G->Gp[u].firsth;
    G->Gp[u].firsth=cur;
}

void init(Graph*G,int count){
    G->Gp=(ArNode*)malloc(sizeof(ArNode)*count);
    for(int i=0;i<count;i++){
        G->Gp[i].firsth=NULL;
    }
}

int* movesToStamp(char* stamp, char* target, int* returnSize) {
    int T_size=strlen(target);
    int S_size=strlen(stamp);
    Graph G;
    init(&G,T_size+1);
    int *error=(int*)malloc(sizeof(int)*(T_size-S_size+1));
    memset(error,0,sizeof(int)*(T_size-S_size+1));
    for(int i=0;i<T_size-S_size+1;i++){
        for(int j=0;j<S_size;j++){
            if(target[i+j]!=stamp[j]){
            error[i]++;
            addNode(i+j,i,&G);
            }
        }
    }
    int*qeueu=(int*)malloc(sizeof(int)*(T_size-S_size+1));
    int left=0,r=0;
    for(int i=0;i<T_size-S_size+1;i++){
        if(error[i]==0)qeueu[r++]=i;
    }
    int *hash=(int*)malloc(sizeof(int)*T_size);
    memset(hash,0,sizeof(int)*T_size);
    while(left<r){
        int cur=qeueu[left++];
        for(int i=cur;i<cur+S_size;i++){
            if(hash[i]==0){
                hash[i]++;
                Node*cur1=G.Gp[i].firsth;
                while(cur1!=NULL){
                    error[cur1->val]--;
                    if(error[cur1->val]==0)qeueu[r++]=cur1->val;
                    cur1=cur1->next;
                }
            }
        }
    }
    if(r!=T_size-S_size+1){
        *returnSize=0;
        return NULL;
    }
    
    *returnSize=r;
    int*result=(int*)malloc(sizeof(int)*r);
    for(int i=0;i<r;i++){
        result[i]=qeueu[r-i-1];
    }
    return result;
}