class Solution {
private:
TreeNode* solve(vector<int>&nums, int low , int high){
    if(low>high){
        return nullptr;
    }
    int mid = (low+high)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    TreeNode* l = solve(nums, low, mid-1);
    TreeNode* r = solve(nums, mid+1,high);
    root->left = l;
    root->right=r;
    return root;
}

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return solve(nums,low,high);
    }
};