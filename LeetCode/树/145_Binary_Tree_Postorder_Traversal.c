/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void behind(struct TreeNode*head,int*res,int*resSize){
    if(head==NULL)return;
    behind(head->left,res,resSize);
    behind(head->right,res,resSize);
    res[(*resSize)++]=head->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int*res=(int*)malloc(sizeof(int)*2000);
    *returnSize=0;
    behind(root,res,returnSize);
    return res;
}