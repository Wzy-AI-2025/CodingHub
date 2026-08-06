int countPrimes(int n) {
    if(n<2)return 0;
    int *s=(int*)malloc(sizeof(int)*n);
    memset(s,1,sizeof(int)*n);
    for(int i=2;i<n;i++){
        if(s[i]){
            for(long long j=(long long)i*i;j<n;j+=i){
                s[j]=0;
            }
        }
    }
    int ans=0;
    for(int i=2;i<n;i++){
        if(s[i])ans++;
    }
    return ans;
}