class Solution {
private:
    void solve(TreeNode* root, string curr, vector<string>& ans) {

        if (root == nullptr)
            return;

        curr += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(curr);
            return;
        }

        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }

public:
    int sumRootToLeaf(TreeNode* root) {

        vector<string> ans;

        solve(root, "", ans);

        int sum = 0;

        for (string s : ans) {
            sum += stoi(s, nullptr, 2);   // Convert binary string to decimal
        }

        return sum;
    }
};