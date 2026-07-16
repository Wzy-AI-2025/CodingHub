char* minWindow(char* s, char* t) {
    int sSize=strlen(s);
    int tSize=strlen(t);
    if(tSize>sSize)return s+sSize;
    int debet=0;//统计目标元素是否收集完毕
    int hash[256];//记录窗口里面的元素
    memset(hash,0,sizeof(hash));
    for(int i=0;i<tSize;i++){
        hash[t[i]]--;
        debet--;
    }
    int left=0;
    int start=0;
    int length=sSize+1;
    for(int right=0;right<sSize;right++){
        if(hash[s[right]]++<0)debet++;//如果hash[i]++前小于0，说明该元素是需要的目标元素
        while(hash[s[left]]>0){
        hash[s[left]]--;
        left++;
        }
        if(debet==0){
            if(right-left+1<length){
                length=right-left+1;
                start=left;
            }
        }
    }
    if(length==sSize+1)return s+sSize;
    char *result=(char*)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++){
        result[i]=s[i+start];
    }
    result[length]='\0';//记得末尾要有结束符
    return result;
}