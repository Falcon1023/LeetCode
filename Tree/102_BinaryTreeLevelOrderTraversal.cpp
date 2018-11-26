#include <vector>
#include <queue>
#include <cstddef>
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
    queue<TreeNode*> levelNode;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return res;
        levelNode.push(root);
        while (!levelNode.empty()) {
            int level = levelNode.size();
            vector<int> levelRes;
            for (int i = 0; i < level; ++i) {
                TreeNode* tmp = levelNode.front();
                levelNode.pop();
                levelRes.push_back(tmp->val);
                if (tmp->left != NULL)
                    levelNode.push(tmp->left);
                if (tmp->right != NULL)
                    levelNode.push(tmp->right);
            }
            res.push_back(levelRes);
        }
        return res;
    }
};

