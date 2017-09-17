#include <iostream>
#include <vector>
#include <deque>
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
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<int> myV;
	vector<vector<int>> G;
	deque<TreeNode*> myQ;
	/**/
	if (!root){return G;}
	else
	{
		myQ.push_back(root);
		myQ.push_back(NULL);
		while (!myQ.empty())
		{
			/*这里注意区分，当myQ里ONLY有1个NULL的情况*/
      			if (myQ.front()==NULL && myQ.size()!=1)
			{
				G.push_back(myV);
				myQ.pop_front();
				myQ.push_back(NULL);
				myV.clear();
			}
			else if (myQ.front()==NULL && myQ.size()==1)
			{
				G.push_back(myV);
				myQ.pop_front();
			}
			else
			{
				myV.push_back(myQ.front()->val);
				if (myQ.front()->left){myQ.push_back(myQ.front()->left);}
				if (myQ.front()->right){myQ.push_back(myQ.front()->right);}
				myQ.pop_front();
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
	G = levelOrder(root);
	for (int i=0;i<G.size();i++)
	{
		for (int j=0;j<G[i].size();j++)
		{
			cout<<G[i][j]<<endl;
		}
	}
	return 0;
}
