 bool check(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if (!root){return true;}
        if (min && root->val<=min->val){return false;}
        if (max && root->val>=max->val){return false;}
        return (check(root->left,min,root)&&check(root->right,root,max));
    }
    //这个check程序没用INT_MIN，而是用的NULL的两个树
    bool isValidBST(TreeNode* root) {
        bool flag = false;
        flag = check(root,NULL,NULL);
        return flag;
        
    }
