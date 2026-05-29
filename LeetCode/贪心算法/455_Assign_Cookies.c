int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int slow=0;
    qsort(g,gSize,sizeof(int),cmp);
    qsort(s,sSize,sizeof(int),cmp);
    for(int fast=0;fast<sSize;fast++){
        if(s[fast]>=g[slow])slow++;
        if(slow==gSize)return gSize;
    }
    return slow;
}