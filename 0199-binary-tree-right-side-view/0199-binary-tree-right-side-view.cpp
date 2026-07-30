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
vector<int> ans;
private:
void bfs(TreeNode*root){
    if(root==nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> lvl;
        for(int i =0; i < size;i++){
            TreeNode* node = q.front();
            q.pop();
            lvl.push_back(node->val);
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
            

        }
        ans.push_back(lvl[lvl.size()-1]);
        
        

    }
}
public:
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};