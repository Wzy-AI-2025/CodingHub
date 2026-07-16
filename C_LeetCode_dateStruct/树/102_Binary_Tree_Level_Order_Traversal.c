/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL; 
        return NULL;
    }
    
    struct TreeNode** denue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    int right = 0;
    denue[right++] = root;
    int count = 0;

   
    int **res = (int**)malloc(sizeof(int*) * 2000);

    int left = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000); 

    while(right > left){
        int size = right - left;
        (*returnColumnSizes)[count] = size;

        res[count] = (int*)malloc(sizeof(int) * size);

        int sit = 0;
        for(int i = 0; i < size; i++){
            if(denue[left]->left != NULL) denue[right++] = denue[left]->left;
            if(denue[left]->right != NULL) denue[right++] = denue[left]->right;
            res[count][sit++] = denue[left]->val;
            left++;
        }
        count++;
    }
    *returnSize = count;
    free(denue); 
    return res;
}