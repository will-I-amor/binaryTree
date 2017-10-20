#include <iostream>
#include <stack>
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
void helper(TreeNode* root,int sum, vector<vector<int>>& G,vector<int>& myS)
{
    if(!root) return;
    myS.push_back(root->val);
    if (!(root->left) && !(root->right) && sum==root->val)
    {
        G.push_back(myS);
    }
    /*if(sum<0)
    {
        if(!myS.empty())
        {
            sum+=myS.back();
            myS.pop_back();
        }
        return;
    }*/
    //sum = sum - root->val;
    helper(root->left,sum-root->val,G,myS);
    helper(root->right,sum-root->val,G,myS);
    myS.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> G;
    vector<int> myS;
    helper(root,sum,G,myS);
    return G;
}
void printVec(vector<int> myV)
{
    for(int i=0;i<myV.size();i++)
    {
        cout<<myV[i]<<",";
    }
}
int main()
{
    vector<vector<int>> G;
    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->right->right->left = newNode(5);
    root->right->right->right = newNode(1);
    root->left->left = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    int sum = 22;
    G = pathSum(root,22);
    for (int i=0;i<G.size();i++)
    {
        cout<<"[";
        printVec(G[i]);
        cout<<"]"<<endl;
    }
    return 0;
}
