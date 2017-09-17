#include <iostream>
#include <stack>
#include <deque>
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
vector<vector<int>> level(TreeNode* root)
{
    vector<int> myV;
    vector<vector<int>> G;
    vector<vector<int>> myG;
    deque<TreeNode*> myQ;
    if (!root){return G;}
    else
    {
        myQ.push_back(root);
        myQ.push_back(NULL);
        while (!myQ.empty())
        {
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
        vector<int>aVec;
        for(int i=G.size()-1;i>=0;i--)
        {
            for(int j=0;j<G[i].size();j++)
            {
                aVec.push_back(G[i][j]);
                cout<<"G[i][j]"<<G[i][j]<<endl;
            }
            myG.push_back(aVec);
            aVec.clear();
        }
        return myG;
    }
}
int main()
{
    vector<vector<int>> G;
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    //root->left->left = newNode(3);
    //root->left->right = newNode(4);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    G = level(root);
    cout<<"G size:"<<G.size()<<endl;
    for (int i=0;i<G.size();i++)
    {
        for (int j=0;j<G[i].size();j++)
        {
            cout<<G[i][j]<<endl;
        }
    }
    return 0;
}
