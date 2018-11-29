#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return dfs(root, sum, 0);
    }
    
    bool dfs(TreeNode* node, int sum, int cur) {
        bool res = false;
        cur += node->val;
        if (node->left == NULL && node->right == NULL)
            res = res || sum == cur;
        else {
            if (node->left != NULL)
                res = res || dfs(node->left, sum, cur);
            if (node->right != NULL)
                res = res || dfs(node->right, sum, cur);
        }
        return res;
    }
};