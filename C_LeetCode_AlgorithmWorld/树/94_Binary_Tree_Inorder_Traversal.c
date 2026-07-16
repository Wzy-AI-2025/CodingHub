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
 void mid(struct TreeNode*head,int*resSize,int *res){
    if(head==NULL)return;
    mid(head->left,resSize,res);
    res[(*resSize)++]=head->val;
    mid(head->right,resSize,res);
 }
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res=(int*)malloc(sizeof(int)*2000);
    *returnSize=0;
    mid(root,returnSize,res);
    return res;
}