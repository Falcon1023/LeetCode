#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int max = 0;
    int cur = 0;
public:
    int maxDepth(TreeNode* root) {
        dfs(root);
        return max;
    }

    void dfs(TreeNode* root) {
        if (root != NULL) {
            ++cur;
            max = max > cur ? max : cur;
            if (root->left != NULL) {
                dfs(root->left);
                --cur;
            }
            if (root->right != NULL) {
                dfs(root->right);
                --cur;
            }
        }
    }
};
