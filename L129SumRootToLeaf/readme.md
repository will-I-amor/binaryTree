###### 题目
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

        1
       / \
      2   3
    
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

###### 解法：
比如二叉树是

                  9
                 /  \
                7     8
               / \   / \
              6   2  1  3
      
那么就应该是976+972+981+983的sum

用preorder的方法遍历二叉树，很聪明的code是：

    val = val*10+node->data;
就是每遍历到root结点，或者下面left,right都是NULL的叶结点，就这样加。然后每次遍历到6,2,1,3这样的没有left,right的叶结点时，把976(结果)放进result数组里。

------------------------------
###### 之前错误的(程序没有按照理想output)想法：
之前我的思路是搞一个nums[]，把9,7,6分别放进nums，然后把6pop出来，再放2进去。但是我是在：

    if (node->left==NULL && node->right==NULL){
    
这一步把6放进去，然后再pop出来，就有点问题。
