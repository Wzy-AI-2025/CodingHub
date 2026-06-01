/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int k = 0;           // 用来记录结果有多少个
int queen[9];        // queen[row]==col表示第row行的皇后在第col列
int safe(int row, int col) {//检查这个位置安不安全
    for (int i = 0; i < row; i++) {
        if (queen[i] == col ||                // 同列
            abs(queen[i] - col) == row - i)   // 对角线
            return 0;
    }
    return 1;
}
void turn(char***result,int n) { // 用来填充结果
    for (int i = 0; i < n; i++) {
        result[k][i][n] = '\0';
        for (int j = 0; j < n; j++) {
            if (queen[i] == j)
                result[k][i][j] = 'Q';
            else
                result[k][i][j] = '.';
        }
    }
    return;
}
void dfs(int row,int s,char***result,int n){
    if(s==n){
        turn(result,n);
        k++;
        return;
    }
    for(int col=0;col<n;col++){
        if(safe(row,col)){
        queen[row]=col;//如果这个点安全设为皇后点
        dfs(row+1,s+1,result,n);//探索下一行
        }
    }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    k=0;
    char*** result = (char***)malloc(sizeof(char**) * 354);
    *returnColumnSizes = malloc(354 * sizeof(int));
    for (int i = 0; i < 354; i++) {
        result[i] = (char**)malloc(sizeof(char*) * n);
        for (int j = 0; j < n; j++) {
            result[i][j] = malloc((n+1) * sizeof(char));
        }
    }

    dfs(0,0,result,n);
    *returnSize=k;
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = n; 
    }
    return result;
}