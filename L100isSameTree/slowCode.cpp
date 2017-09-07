#include <iostream>
#include <vector>
using namespace std;
/*之前第20行到第24行运行时会出现错误的答案，因为之前写的是if (p||q),当input是0和0或者1和1时，总会return false;
我就把if(p||q)拆开来写,变成if(p&&!q)和if(!p&&q)*/
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* newNode(int n){
	TreeNode* node = new TreeNode;
	node->val = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
bool isSameTree(TreeNode*p,TreeNode*q)
{
	if (!p&&!q)
		{	cout<<"1"<<endl;
			return true;}
    if (p&&!q)
    	{	cout<<"2"<<endl;
    		return false;}
    if (!p&&q)
    {
    	cout<<"3"<<endl;
    	return false;
    }
    if (p&&q&&p->val==q->val)
    {	cout<<"4"<<endl;
    	return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));}
    return true;
}
int main(){
	TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(10);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(6);
	bool flag = false;
	TreeNode* node = newNode(6);
	node->left = newNode(2);
	node->right = newNode(7);
	//flag = isSameTree(root,node);
	TreeNode* p = newNode(0);
	TreeNode* q = newNode(0);
	flag = isSameTree(p,q);
	cout<<flag<<endl;
	return 0;
}
