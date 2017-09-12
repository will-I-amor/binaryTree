class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root){return 0;}
        else
        {
            int h = 0;
            int left = 1 + maxDepth(root->left);
            int right = 1 + maxDepth(root->right);
            if (left>right){h = left;}
            else{h = right;}
            return h;
        }
    }
};
