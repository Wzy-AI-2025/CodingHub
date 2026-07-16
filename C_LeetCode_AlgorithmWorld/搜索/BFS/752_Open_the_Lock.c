int front(int cur,int n){
    int res[4];
     res[0]=cur/1000;
     res[1]=cur%1000/100;
     res[2]=cur%100/10;
     res[3]=cur%10;
    if(res[n]==9)res[n]=0;
    else res[n]++;
    return res[0]*1000+res[1]*100+res[2]*10+res[3];
}//向前
int behind(int cur,int n){
    int res[4];
     res[0]=cur/1000;
     res[1]=cur%1000/100;
     res[2]=cur%100/10;
     res[3]=cur%10;
    if(res[n]==0)res[n]=9;
    else res[n]--;
    return res[0]*1000+res[1]*100+res[2]*10+res[3];
}//向后
int change(char*s){
    int sum=0;
    for(int i=0;i<4;i++){
        sum=sum*10+(s[i]-'0');
    }
    return sum;
}
int openLock(char** deadends, int deadendsSize, char* target) {
    int target1=change(target);
    int record[10000]={0};//标记走过的路线
    int dist[10000]={0};//标记反转次数
    for(int i=0;i<deadendsSize;i++){
        int result=change(deadends[i]);
        record[result]=1;
    }
    if(record[0]==1)return -1;
    int *deque=(int*)malloc(sizeof(int)*10000);
    int left=0;
    int right=0;
    deque[right++]=0;
    record[0]=1;
    while(left<right){
        int cur=deque[left];
        if(cur==target1)return dist[cur];
        for(int i=0;i<4;i++){
            int result=front(cur,i);
            if(record[result]==0){
            deque[right++]=result;
            dist[result]=dist[cur]+1;
            record[result]=1;
            }
            result=behind(cur,i);
            if(record[result]==0){
            deque[right++]=result;
            dist[result]=dist[cur]+1;
            record[result]=1;
            }
        }
        left++;
    }
    return -1;
}