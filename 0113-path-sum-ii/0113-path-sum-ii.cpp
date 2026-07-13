/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void solve(TreeNode* root , vector<int> &curr , vector<vector<int>>&ans , int target){
        if(root == nullptr){
            return;
        }
        curr.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(target == root->val){
                ans.push_back(curr);
            }
            curr.pop_back();
            return;
        }
        solve(root->left , curr, ans , target-root->val);
        solve(root->right, curr, ans , target-root->val);
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(root , curr, ans, targetSum);
        return ans;
    }
};