int totalFruit(int* fruits, int fruitsSize) {
    int hash[fruitsSize];
    memset(hash,0,sizeof(hash));
    int kinds=0;
    int left=0;
    int len=0;
    for(int right=0;right<fruitsSize;right++){
        if(hash[fruits[right]]==0)kinds++;
        hash[fruits[right]]++;
        if(kinds<=2){
            if(right-left+1>len)len=right-left+1;
        }
        while(kinds>=3){
            hash[fruits[left]]--;
            if(hash[fruits[left]]==0)kinds--;
            left++;
        }
    }
    return len;
}