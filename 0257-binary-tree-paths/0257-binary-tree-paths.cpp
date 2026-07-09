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
    void solve(TreeNode* root, vector<int>& curr, vector<string>& ans) {

        if (root == nullptr) {
            return;
        }

        curr.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {

            string a = "";

            for (int i = 0; i < curr.size(); i++) {
                a += to_string(curr[i]);

                if (i != curr.size() - 1)
                    a += "->";
            }

            ans.push_back(a);

            curr.pop_back();
            return;
        }

        solve(root->left, curr, ans);
        solve(root->right, curr, ans);

        curr.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        vector<int> curr;

        solve(root, curr, ans);

        return ans;
    }
};