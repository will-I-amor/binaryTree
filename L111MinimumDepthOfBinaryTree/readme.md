Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

考虑2种情况

        4
       /
      5
     /
    6
这种情况4那里应该返回3，但是4的right是null，如果返回min(left,right)的话，只会返回0+1，这个是错的
所以我们要分2种情况来返回，if(!root-right){return minDepth(root->left)+1;}

![](https://i.imgur.com/9byEVsm.jpg)
