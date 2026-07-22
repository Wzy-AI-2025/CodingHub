void initNext(char*s,int *next,int size){
    next[0]=-1;
    if(size==1)return;
    next[1]=0;
    int cnt=0;//从0开始比对
    int i=2;
    while(i<size){
        if(s[i-1]==s[cnt]){
            next[i]=cnt+1;
            cnt++;
            i++;
        }
        else if(cnt>0){
            cnt=next[cnt];
        }//这里判断条件可以换成next[cnt]>=0,下面也是同理
        else{
            next[i++]=0;
        }
    }
}

int strStr(char* haystack, char* needle) {
    int haystackSize=strlen(haystack);
    int needleSize=strlen(needle);
    if(haystackSize<needleSize)return -1;
    int next[needleSize];
    initNext(needle,next,needleSize);
    int x=0,y=0;
    while(x<haystackSize&&y<needleSize){
        if(haystack[x]==needle[y]){
            x++;
            y++;
        }
        else if(next[y]>=0){
            y=next[y];
        }
        else{
            x++;
        }
    }
    return y==needleSize?x-y:-1;
}