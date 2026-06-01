#include <stdlib.h>

void dfs(int* nums, int numsSize, int depth, int* path, bool* used,
         int* returnSize, int** result) {
    if (depth == numsSize) {
        // 复制当前路径到结果中
        result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = true;
            path[depth] = nums[i];
            dfs(nums, numsSize, depth + 1, path, used, returnSize, result);
            used[i] = false; // 回溯
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 计算全排列数量: n!
    *returnSize = 1;
    for (int i = 2; i <= numsSize; i++) {
        *returnSize *= i;
    }

    // 分配结果数组
    int** result = (int**)malloc(sizeof(int*) * (*returnSize));
    
    // 分配列大小数组
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    // 辅助数组
    int* path = (int*)malloc(sizeof(int) * numsSize);
    bool* used = (bool*)calloc(numsSize, sizeof(bool)); // 初始化为 false

    // 重置 returnSize 为 0，用于 dfs 中计数
    int count = 0;
    dfs(nums, numsSize, 0, path, used, &count, result);

    free(path);
    free(used);
    *returnSize = count;

    return result;
}