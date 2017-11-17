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
	TreeNode* cur = root;
	vector<int>vec;
	if(!root) return vec;
	vec.push_back(cur->val);
	while (root!=NULL)
	{
		if(root->left==NULL)
		{
			vec.push_back(root->val);
			//cout<<"at one:"<<root->val<<"     ";
			printf("%d",root->val);
			root = root->right;
		}
		else
		{
			/*if(prev==NULL || prev->right!=root)
			{
				vec.push_back(root->val);
				//printf("%d",root->val);
				cout<<"at two:"<<root->val<<"     ";
			}*/
			prev = root->left;
			while (prev->right!=NULL && prev->right!=root)
			{
				prev = prev->right;//这一步是一直算prev，直到prev到达最右端
			}
			if (prev->right==NULL)
			{
				vec.push_back(root->val);//应该改这一步！！！！
				printf("%d",root->val);
				prev->right = root;
				root = root->left;
			}
			else//prev->right==root
			{
				prev->right=NULL;
				root = root->right;
			}
		}
	}
	return vec;
}
int main(){
	TreeNode* root = newNode(6);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->left->right->right = newNode(5);

	//root->right->left = newNode(4);
	root->right->right = newNode(9);
	root->right->right->left = newNode(8);
	vector<int>vec;
	vec = inOrder(root);
	for (int i = 0;i<vec.size();i++)
	{
		cout<<vec[i]<<endl;
	}
	cout<<endl;
	return 0;
}
