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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue <TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            ans.push_back({});    
            
            vector<TreeNode*> nodes;
            while(!q.empty()){
                TreeNode* cur = q.front();
                q.pop();
                nodes.push_back(cur);    
            }
            for(auto n : nodes) {
                if(n) {
                    ans[level].push_back(n->val);
                    q.push(n->left);
                    q.push(n->right);
                }
            }
            level ++;
        }
        ans.pop_back();
        return ans;
    }
};