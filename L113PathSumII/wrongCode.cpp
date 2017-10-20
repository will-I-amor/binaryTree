class Solution {
public:
    void helper(TreeNode* root,int sum, vector<vector<int>>& G,vector<int>& myS)
    {
        if(!root && sum!=0)//on leaf node && sum!=0
        {
            if(!myS.empty())
            {
                sum+=myS.back();
                myS.pop_back();
            }
            return;
        }
        if (sum==0)
        {
            if(!myS.empty()) G.push_back(myS);
            /*for(vector<int>::iterator it = myS.begin();it!=myS.end();++it)
            {
                sum += *it;
            }*/
            //myS.erase(myS.begin(),myS.end());
            if(!myS.empty()) myS.pop_back();
            return;
        }
        if(sum<0)
        {
            if(!myS.empty())
            {
                sum+=myS.back();
                myS.pop_back();
            }
            return;
        }
        sum = sum-root->val;
        myS.push_back(root->val);
        helper(root->left,sum,G,myS);
        helper(root->right,sum,G,myS);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> G;
        vector<int> myS;
        helper(root,sum,G,myS);
        return G;
    }
};
