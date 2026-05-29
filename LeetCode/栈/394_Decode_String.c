char* decodeString(char* s) {
    int numStack[1000], numTop = -1;
    char strStack[1000][5000];
    int strTop = -1;

    char cur[5000] = {0};
    int num = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            numStack[++numTop] = num;
            num = 0;
            strTop++;
            strcpy(strStack[strTop], cur);
            memset(cur, 0, sizeof(cur));
        } else if (s[i] == ']') {
            int k = numStack[numTop--];
            char temp[5000];
            strcpy(temp, cur);
            strcpy(cur, strStack[strTop--]);
            for (int j = 0; j < k; j++) {
                strcat(cur, temp);
            }
        } else {
            int len = strlen(cur);
            cur[len] = s[i];
            cur[len + 1] = '\0';
        }
    }

    char* res = malloc(strlen(cur) + 1);
    strcpy(res, cur);
    return res;
}