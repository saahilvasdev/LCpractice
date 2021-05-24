class ResultType {
public:
    int longestDia;
    int longestPath;
    ResultType(int dia = 0, int path = 0): longestDia(dia), longestPath(path) {}
};

class Solution {
public:
    /**
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        ResultType res = dfs(root);
        return res.longestDia;
    }
    
    ResultType dfs(TreeNode *root) {
        if (!root) {
            return ResultType(0, 0);
        }
        
        ResultType leftRes = dfs(root->left);
        ResultType rightRes = dfs(root->right);
        
        int maxDia = max(leftRes.longestPath + rightRes.longestPath, 
                        max(leftRes.longestDia, rightRes.longestDia));
        int maxPath = max(leftRes.longestPath, rightRes.longestPath) + 1;
        ResultType cur(maxDia, maxPath);
        
        return cur;
    }
};