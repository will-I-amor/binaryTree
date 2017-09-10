#include <iostream>
#include <vector>
#include <stack>
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
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> G;
	vector<int> vec;
	stack<TreeNode*> a;
	stack<TreeNode*> b;
	if (!root){return G;}
	else
	{
		a.push(root);
		while (!a.empty() || !b.empty())
		{
			while (!a.empty())
			{
				if (a.top()->left){b.push(a.top()->left);}
				if (a.top()->right){b.push(a.top()->right);}
				vec.push_back(a.top()->val);
				a.pop();
			}
			G.push_back(vec);
			vec.clear();
			while(!b.empty())
			{
				if (b.top()->right){a.push(b.top()->right);}
				if (b.top()->left){a.push(b.top()->left);}
				vec.push_back(b.top()->val);
				b.pop();
			}
			if (vec.size()!=0)
			{
				G.push_back(vec);
				vec.clear();
			}
		}
	}
	return G;
}
int main(){
	TreeNode* root = newNode(6);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	//root->right->left = newNode(4);
	root->right->right = newNode(9);
	vector<vector<int>> G;
	G = zigzagLevelOrder(root);
	for (int i=0;i<G.size();i++)
	{
		for (int j=0;j<G[i].size();j++)
		{
			cout<<G[i][j]<<endl;
		}
	}
	return 0;
}
