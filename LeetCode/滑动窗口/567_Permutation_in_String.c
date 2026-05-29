bool checkInclusion(char* s1, char* s2) {
    int s1Size=strlen(s1);
    int s2Size=strlen(s2);
    if(s1Size>s2Size)return 0;
    int hash[26];
    memset(hash,0,sizeof(hash));
    for(int i=0;i<s1Size;i++){
        hash[s1[i]-'a']--;
    }
    int left=0;
    for(int right=0;right<s2Size;right++){
        int turn=1;
        hash[s2[right]-'a']++;
        if(right-left+1>s1Size){
            hash[s2[left]-'a']--;
            left++;
        }
        if(right-left+1==s1Size){
            for(int i=0;i<26;i++){
                if(hash[i]!=0)turn=0;
            }
        }
        if(turn&&right-left+1==s1Size){
            return 1;
        }
    }
    return 0;
}