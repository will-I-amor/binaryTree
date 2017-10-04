
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root){return true;}
        int left_height = height(root->left);
        int right_height = height(root->right);
        return (abs(left_height - right_height)<=1 && isBalanced(root->left) && isBalanced(root->right));
    }
private:
    int height(TreeNode* root)
    {
        if(!root){return 0;}
        return max(height(root->left),height(root->right))+1;
    }
};
