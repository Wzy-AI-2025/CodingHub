int ans = 0;

int depth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    ans = ans > l + r ? ans : l + r;
    return (l > r ? l : r) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    ans = 0;
    depth(root);
    return ans;
}//