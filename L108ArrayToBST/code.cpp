class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums,0,(nums.size()-1));
    }
    TreeNode* help(vector<int>& nums, int start, int end)
    {
        if(start>end){return NULL;}
        int mid = start+(end-start)/2;
        //之前这个mid的求法算错了，写成mid = (end-start)/2了
        //后来改成mid = (start+(end-start))/2也是错的
        //要注意mid的求法
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(nums,start,mid-1);
        root->right = help(nums,mid+1,end);
        return root;
    }
};
