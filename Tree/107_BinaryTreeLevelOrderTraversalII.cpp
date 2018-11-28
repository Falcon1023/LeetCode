#include <cstddef>
#include <vector>
#include <queue>
#include <algorithm>
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
    queue<TreeNode*> tree;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return res;
        tree.push(root);
        while (!tree.empty()) {
            int level = tree.size();
            vector<int> levelRes;
            for (int i = 0; i < level; ++i) {
                TreeNode* tmp = tree.front();
                tree.pop();
                levelRes.push_back(tmp->val);
                if (tmp->left != NULL)
                    tree.push(tmp->left);
                if (tmp->right != NULL)
                    tree.push(tmp->right);
            }
            res.push_back(levelRes);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};