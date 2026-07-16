int sumSubarrayMins(int* arr, int arrSize) {
    long long sum=0;
    int stack[30000];
    int r=0;
    for(int i=0;i<arrSize;i++){
        while(r>0&&arr[i]<=arr[stack[r-1]]){
           int left=r==1?-1:stack[r-2];
           sum+=(stack[r-1]-left)*(i-stack[r-1])*arr[stack[r-1]];
           sum%=(1000000000+7);
           r--;
        }
        stack[r++]=i;
    }
    while(r>0){
        int left=r==1?-1:stack[r-2];
        sum+=(long long)((stack[r-1]-left)*(arrSize-stack[r-1]))*arr[stack[r-1]];
        sum%=(1000000000+7);
        r--;
    }
    return sum;
}