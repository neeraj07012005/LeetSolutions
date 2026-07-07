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
    bool solve(TreeNode* root, int targetSum , int sum){

        if(root == nullptr){      // added
            return false;
        }

        if(root->left==nullptr && root->right == nullptr){
            if(sum + root->val == targetSum){   // changed
                return true;
            }
            else{
                return false;
            }
        }

        bool a = solve(root->left , targetSum , sum + root->val);
        bool b = solve(root->right, targetSum , sum + root->val);

        if(a == true || b == true){
            return true;
        }
        else{
            return false;
        }

    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum , 0);
    }
};