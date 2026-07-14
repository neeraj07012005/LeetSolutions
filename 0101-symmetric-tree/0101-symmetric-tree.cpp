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
    bool solve(TreeNode* left, TreeNode* right) {

        // Both nodes are empty
        if (left == nullptr && right == nullptr)
            return true;

        // One node is empty
        if (left == nullptr || right == nullptr)
            return false;

        // Values don't match
        if (left->val != right->val)
            return false;

        // Check outer and inner children
        bool leftMirror = solve(left->left, right->right);
        bool rightMirror = solve(left->right, right->left);

        return leftMirror && rightMirror;
    }

public:
    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return true;

        return solve(root->left, root->right);
    }
};