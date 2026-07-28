int fib(int n) {
    if(n==0)return 0;
    if(n==1)return 1;
    int last=0;
    int laster=1;
    int sum;
    for(int i=0;i<n-1;i++){
        sum=last+laster;
        last=laster;
        laster=sum;
    }
    return sum;
}