bool isValid(char* s) {
    int sSize=strlen(s);
    if(sSize%2!=0)return 0;
    int r=0;
    int record[10000];
    for(int i=0;i<sSize;i++){
        if(s[i]=='[')record[i]=-1;
        else if(s[i]==']')record[i]=1;
        else if(s[i]=='(')record[i]=-2;
        else if(s[i]==')')record[i]=2;
        else if(s[i]=='{')record[i]=-3;
        else record[i]=3;
    }//做一个转换，方便理解
    int stack[10000]={0};
    for(int i=0;i<sSize;i++){
        if(record[i]<0)stack[r++]=record[i];
        else{
            if(r<1||(record[i]+stack[r-1])!=0)return 0;
            if(record[i]+stack[r-1]==0)r--;
        }
    }
    if(r==0)return 1;
    return 0;
}