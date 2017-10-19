class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){return false;}
        if(!root->right && !root->left){return root->val==sum;}
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};
