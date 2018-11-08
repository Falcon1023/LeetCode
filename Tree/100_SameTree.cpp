#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = false;
        if (p == NULL && q == NULL)
            res = true;
        else if (p != NULL && q != NULL && p->val == q-> val)
            res = (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        return res;
    }
};