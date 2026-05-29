int findTheLongestSubstring(char* s) {
    int hash[32];
    for(int i=0;i<32;i++){
        hash[i]=-2;
    }
    hash[0]=-1;
    int sum=0;
    int len=0;
    int sSize=strlen(s);
    for(int i=0;i<sSize;i++){
        switch(s[i]){
            case('a'):sum^=1<<0;break;
            case('e'):sum^=1<<1;break;
            case('i'):sum^=1<<2;break;
            case('o'):sum^=1<<3;break;
            case('u'):sum^=1<<4;break;
        }
        if(hash[sum]!=-2&&i-hash[sum]>len)len=i-hash[sum];
        if(hash[sum]==-2)hash[sum]=i;
    }
    return len;
}