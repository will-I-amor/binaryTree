难点在于不仅要一颗树一颗树地recur，而且左/右孩子的孩子也不能比root大/小
比如

      10
     /  \
    5    15
        /  \
       6   20
     
这就不是一颗BST，但是如果按每颗树这样recur，会返回true. 

所以要用INT_MIN,和INT_MAX.

    bool check(TreeNode* root,int min,int max)
    return (check(root->left,min,root->val)&&check(root->right,root->val,max));
    所有左面的孩子，会有个max值来比较；所有右面孩子，会有个min值来比较
    这样就可以保证，整棵树都是BST了
