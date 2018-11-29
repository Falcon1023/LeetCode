#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return res;
        dfs(root, sum, 0);
        return res;
    }
    
    void dfs(TreeNode* node, int sum, int cur) {
        cur += node->val;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL && sum == cur)
            res.push_back(path);
        else {
            if (node->left != NULL)
                dfs(node->left, sum, cur);
            if (node->right != NULL)
                dfs(node->right, sum, cur);
        }
        path.pop_back();
    }
};