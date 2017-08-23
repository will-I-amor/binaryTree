    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    But the following [1,2,2,null,3,null,3] is not:
        1
       / \
      2   2
       \   \
        3    3
        
###### 我原来的想法是用
    bool isSymmetric(Node* root1, Node* root2)
###### 创建2个binary trees.但是速度非常慢。
###### 其中体会这个函数是怎么传参的，还有3个if后一定要有else
    if (root1==NULL && root2==NULL)
      {return true;}
	if (root1==NULL || root2==NULL)
		{return false;}
	if (root1 && root2 && root1->data==root2->data){
			return isSymmetric(root1->right,root2->left) && isSymmetric(root1->left,root2->right);
		}
	else{
		return false;
	}
###### 否则编译会不通过，报错比如：
    warning: control may reach end of non-void function
      [-Wreturn-type]

	
## 怎样用iteration的方式写一个？
