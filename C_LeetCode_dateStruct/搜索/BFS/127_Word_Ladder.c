typedef struct {
        int process;
        char* word;
    } point;
int check(char* ch, char* sh) {
    int s = strlen(ch);
    int space = 1;
    for (int i = 0; i < s; i++) {
        if (ch[i] != sh[i])
            space--;
    }
    if (space == 1)
        return -1;
    return space == 0 ? 1 : 0;
}
int ladderLength(char* beginWord, char* endWord, char** wordList,
                 int wordListSize) {
    int size = strlen(beginWord);
    point dneue[5001];
    for(int i=0;i<5001;i++){
        dneue[i].word=(char*)malloc(sizeof(char)*(size+1));
    }
    int left = 0;
    int right = 0;
    dneue[right].process = 1;
    int record[5000] = {0};
    strcpy(dneue[right++].word, beginWord);
    while (left < right) {
        if (check(dneue[left].word, endWord) == -1)
            return dneue[left].process;
        point cur = dneue[left];
        for (int i = 0; i < wordListSize; i++) {
            if (check(cur.word, wordList[i]) == 1 && record[i] == 0) {
                strcpy(dneue[right].word, wordList[i]);
                dneue[right++].process = dneue[left].process + 1;
                record[i] = 1;
            }
        }
        left++;
    }
    return 0;
}