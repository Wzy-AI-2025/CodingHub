/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int sSize=strlen(s);
    int pSize=strlen(p);
    *returnSize=0;
    if(sSize<pSize)return NULL;
    int *m=(int*)malloc(sizeof(int)*sSize);
    int hash[256];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<pSize;i++){
        hash[p[i]]--;
    }
    int count=0;
    int left=0;
    for(int right=0;right<sSize;right++){
        int turn=1;
        hash[s[right]]++;
        if(right-left+1>pSize){
            hash[s[left++]]--;
        }
        if(right-left+1==pSize){
            for(int j=0;j<256;j++){
                if(hash[j]!=0){
                    turn=0;
                    break;
                }
            }
        }
        if(turn&&right-left+1==pSize)m[count++]=left;
    }
    *returnSize=count;
    return m;
}