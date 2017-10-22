class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;//特殊情况，root为NULL时return
        if(root->next==nullptr)
        {
            root->next = nullptr;//为了最开始时候的root结点服务的
        }
        if(root->next ==nullptr && root->right &&root->left)
        {
            root->right->next = nullptr;
        }
        if(root->next && root->right && root->left)
        {
            root->right->next = root->next->left;//当遍历到左子树时，check一下root->next是否为NULL
        }
        if(!root->left && !root->right) return;//当base case是leaf node时，return
        root->left->next = root->right;//在current root这个情况下，先把root的左孩子的next连到右孩子上
        connect(root->right);
        connect(root->left);
    }
};
