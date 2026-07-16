// 查找根节点（带路径压缩）
int find(int* board, int x) {
    if (board[x] != x) {
        board[x] = find(board, board[x]);
    }
    return board[x];
}
// 合并两个节点
void do_union(int x, int y, int* board, int* sets) {
    int rx = find(board, x);
    int ry = find(board, y);
    if (rx != ry) {
        board[rx] = ry;
        (*sets)--;  // 只有不同集合才合并，sets 减 1
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize[0] == 0) return 0;

    int m = gridSize;          // 行数
    int n = gridColSize[0];    // 列数
    int total = m * n;
    int* board = (int*)malloc(sizeof(int) * total);

    // 初始化并查集
    for (int i = 0; i < total; i++) {
        board[i] = i; 
    }

    int sets = 0;
    // 遍历每个格子
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                sets++;  // 每个 '1' 初始视为一个岛屿
                int idx = i * n + j; 
                // 检查上方
                if (i - 1 >= 0 && grid[i-1][j] == '1') {
                    do_union(idx, (i-1)*n + j, board, &sets);
                }
                // 检查左方
                if (j - 1 >= 0 && grid[i][j-1] == '1') {
                    do_union(idx, i*n + (j-1), board, &sets);
                }
            }
        }
    }
    free(board);
    return sets;
}