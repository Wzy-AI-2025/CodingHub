int longestWPI(int* hours, int hoursSize) {
    int sum=0;
    int*map=(int*)malloc(sizeof(int)*20001);
    for(int i=0;i<20001;i++){
        map[i]=-2;
    }
    int len=0;
    map[10000]=-1;
    for(int i=0;i<hoursSize;i++){
        sum+=hours[i]>8?1:-1;
        int target=sum-1;
        if(sum>0){
            len=i+1;
        }
        else{
        if(map[target+10000]!=-2&&i-map[target+10000]>len)len=i-map[target+10000];
        }
        if(map[sum+10000]==-2)map[sum+10000]=i;
    }
    return len;
}