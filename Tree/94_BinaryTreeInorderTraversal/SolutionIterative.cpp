#include <cstddef>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> res;
    stack<TreeNode*> tree;
    unordered_map<TreeNode*, bool> flag;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return res;
        tree.push(root);
        while (!tree.empty()) {
            TreeNode* tmp = tree.top();
            if (tmp->left && !flag[tmp->left]) {
                tree.push(tmp->left);
                flag[tmp->left] = true;
            } else {
                tree.pop();
                res.push_back(tmp->val);
                if (tmp->right != NULL)
                    tree.push(tmp->right);
            }
        }
        return res;
    }
};

