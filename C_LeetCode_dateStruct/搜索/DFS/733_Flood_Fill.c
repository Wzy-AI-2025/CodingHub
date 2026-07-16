void dfs(int** image, int imageSize, int imageColSize, int sr, int sc, int newColor, int oldColor) {
    // 避免重复填充导致的无限递归，因为这个题目会检查四个方向，我们可以假设颜色相同的情况
    if (oldColor == newColor) return;
    
    // 确保当前坐标在图像范围内，并且颜色匹配
    if (sr >= 0 && sr < imageSize && sc >= 0 && sc < imageColSize && image[sr][sc] == oldColor) {
        image[sr][sc] = newColor;
        
        // 对上下左右四个方向进行递归调用
        dfs(image, imageSize, imageColSize, sr - 1, sc, newColor, oldColor);
        dfs(image, imageSize, imageColSize, sr + 1, sc, newColor, oldColor);
        dfs(image, imageSize, imageColSize, sr, sc - 1, newColor, oldColor);
        dfs(image, imageSize, imageColSize, sr, sc + 1, newColor, oldColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; ++i) {
        (*returnColumnSizes)[i] = imageColSize[0];
    }
    
    int oldColor = image[sr][sc];
    dfs(image, imageSize, imageColSize[0], sr, sc, newColor, oldColor);
    
    return image;
}