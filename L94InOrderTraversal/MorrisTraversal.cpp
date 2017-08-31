#include <iostream>
#include <vector>
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
vector<int> inOrder(TreeNode* root)
{
	TreeNode* prev = NULL;
	vector<int>vec;
	while (root!=NULL)
	{
		if(root->left==NULL)
		{
			vec.push_back(root->val);
			printf("%d",root->val);
			root = root->right;
		}
		else
		{
			prev = root->left;
			while (prev->right!=NULL && prev->right!=root)
			{
				prev = prev->right;
			}
			if (prev->right==NULL)
			{
				prev->right = root;
				root = root->left;
			}
			else//prev->right==root
			{
				vec.push_back(root->val);
				printf("%d",root->val);
				prev->right=NULL;
				root = root->right;
			}
		}
	}
	return vec;
}
int main(){
	TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(10);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(6);
	vector<int>vec;
	vec = inOrder(root);
	for (int i = 0;i<vec.size();i++)
	{
		cout<<vec[i]<<endl;
	}
	cout<<endl;
	return 0;
}
