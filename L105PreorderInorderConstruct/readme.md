preorder是: tLR

inorder是: LtR

    1.也就是preorder的首个item是root结点。
    
    2.在inorder里找到root的位置，把Index记为k。
    
    3.new一个TreeNode，设为即为root的值. TreeNode* root = new TreeNode(preorder[pstart]).pstart就是preorder的第一个位置
    
    4.然后分别设置root->left和root->right。
    
    5.注意传参的问题。root->right里传的参，pstart要变成pstart+(k-istart+1)这个位置，因为要越过左子树
    
    6.pstart+(k-istart+1)这个k-istart是inorder里左子树结点个数

![](https://i.imgur.com/u4YGy02.jpg)
