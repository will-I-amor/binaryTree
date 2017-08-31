    Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
    Given binary tree [1,null,2,3],
       1
        \
         2
        /
       3
    return [1,3,2]

##### iterative1.cpp文件里的教训：
    void inorderTraversal(Node* root)
    {
	stack<Node*> mystack;
	//Node* temp = NULL;
	Node* current = NULL;
	if (root){
		mystack.push(root);
		current = mystack.top()->left;
	}
	while (!mystack.empty() || current)
	{
		if (current){
			mystack.push(current);
			current = current->left;
		}
		else
		{
			cout<<mystack.top()->data<<endl;
			current = mystack.top()->right;
			mystack.pop();
		}
	}
    }
上面的程序，是建一个stack，先把root push进去，然后设current=mystack.top()->left

###### 1) Create an empty stack S.
###### 2) Initialize current node as root
###### 3) Push the current node to S and set current = current->left until current is NULL
###### 4) If current is NULL and stack is not empty then 
######      a) Pop the top item from stack.
######      b) Print the popped item, set current = popped_item->right 
######      c) Go to step 3.
###### 5) If current is NULL and stack is empty then we are done.
    
    while (!mystack.empty() || current)
    之前错在这里了，没有加||current，循环到根节点的时候stack为空了，直接跳出while loop,导致不能继续行进到右子书

##### MorrisTraversal
可以参考这个网站http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
