TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return help(preorder, 0, inorder, 0, inorder.size()-1);
}
TreeNode* help(vector<int>& preorder, int pstart, vector<int>& inorder, int istart, int iend){
    if(istart>iend)
        return NULL;
    TreeNode* root = new TreeNode(preorder[pstart]);
    int k;
    for(int i=istart; i<=iend; i++){
        if(inorder[i] == root->val){
            k = i;
            break;
        }
    }
    root->left = help(preorder, pstart+1, inorder, istart, k-1);
    root->right = help(preorder, pstart+k-istart+1, inorder, k+1, iend);
    return root;
}
