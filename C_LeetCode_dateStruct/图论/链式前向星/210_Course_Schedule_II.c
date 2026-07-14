/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int *head=(int*)malloc(sizeof(int)*numCourses);//下标代表点的编号,值代表边的编号
    int*next=(int*)malloc(sizeof(int)*prerequisitesSize);//下标表示边的编号,值表示指向的点的编号
    int*to=(int*)malloc(sizeof(int)*prerequisitesSize);//下标表示边的编号,指向的点
    int*in_degree=(int*)malloc(sizeof(int)*numCourses);
    int cnt=0;
    memset(head,-1,sizeof(int)*numCourses);
    memset(in_degree,0,sizeof(int)*numCourses);
    for(int i=0;i<prerequisitesSize;i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];
        in_degree[v]++;
        next[cnt]=head[u];
        to[cnt]=v;
        head[u]=cnt++;
    }//本质上模拟邻接表的头插法
    int *qeueu=(int*)malloc(sizeof(int)*numCourses);
    int left=0,r=0;
    for(int i=0;i<numCourses;i++){
        if(in_degree[i]==0)qeueu[r++]=i;
    }
    while(left<r){
        int cur=qeueu[left++];
        int edge=head[cur];//边
        while(edge!=-1){
            in_degree[to[edge]]--;
            if(in_degree[to[edge]]==0)qeueu[r++]=to[edge];
            edge=next[edge];
        }
    }
    *returnSize=r==numCourses?r:0;
    return r==numCourses?qeueu:NULL;
}