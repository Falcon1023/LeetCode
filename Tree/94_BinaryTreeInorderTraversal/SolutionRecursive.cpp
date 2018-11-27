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
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }

    void inorder(TreeNode* root) {
        if (root != NULL) {
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        }
    }
};

