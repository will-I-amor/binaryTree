/*this file only get buggy on LEETCODE,
  because of INT_MIN and INT_MAX
  the check()function
  */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
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
bool check(TreeNode* root,int min,int max)
{
	if (root==NULL){return true;}
	if (root->val<=min || root->val>=max)
		{return false;}
    return (check(root->left,min,root->val)&&check(root->right,root->val,max));
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
	flag = check(root,INT_MIN,INT_MAX);
	cout<<flag<<endl;
	return 0;
}
