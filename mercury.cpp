#include <iostream>
#include <deque>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* newNode(int n){
	TreeNode* node = new TreeNode(n);
	//node->val = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
TreeNode* insert(TreeNode* node, int n){
	if (node == NULL){
		return (newNode(n));
	}
	else{
		if(n<=node->val){
			node->left = insert(node->left, n);
		}
		else{
			node->right = insert(node->right,n);
		}
	}
	return node;
}
void BFSaTree(TreeNode* root,deque<TreeNode*>& mydeque)
{
	if(root==NULL){
		return;
	}
	mydeque.push_back(root);
	TreeNode* p_root = root;
	while(!mydeque.empty())
	{
		if(p_root->left!=NULL){
			mydeque.push_back(p_root->left);
		}
		if(p_root->right!=NULL){
			mydeque.push_back(p_root->right);
		}
		cout<<mydeque.front()->val<<endl;
		mydeque.pop_front();
		p_root = mydeque.front();
	}
}
int main()
{
	TreeNode* node;
	//node = insert(node, 2);
	// node = insert(node, 3);
	// node = insert(node, 1);
	// node = insert(node, 1);
	// node = insert(node, 8);
	// node = insert(node, 9);
	deque<TreeNode*>q;
	BFSaTree(node,q);
	return 0;
}