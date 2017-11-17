Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

此题跟94题类似。就是print出root值的那2步，需要改其中一步，就是47行那步。

在prev->right这一步print root值
