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
	TreeNode* cur, *prev = NULL;
	vector<int>vec;
	while (cur!=NULL)
	{
		if(cur->left==NULL)
		{
			vec.push_back(cur->val);
			printf("%d",cur->val);
			cur = cur->right;
		}
		else
		{
			prev = cur->left;
			while (prev->right!=NULL && prev->right!=cur)
			{
				prev = prev->right;
			}
			if (prev->right==NULL)
			{
				prev->right = cur;
				cur = cur->left;
			}
			else//prev->right==cur
			{
				vec.push_back(cur->val);
				printf("%d",cur->val);
				prev->right=NULL;
				cur = cur->right;
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
