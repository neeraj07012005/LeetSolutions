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
    int dfs(TreeNode* root,int &count){
        if(root == nullptr){
            return INT_MIN;
        }
        //process
        int leftmax = dfs(root->left, count);
        int rightmax = dfs(root->right,count);
        int currmax = max(root->val , max(leftmax , rightmax));
        if(currmax == root->val){
            count++;
        }
        return currmax;
    }
public:
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};