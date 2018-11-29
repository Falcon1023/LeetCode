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
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return res;
    }
    
    void preOrder(TreeNode* node) {
        if (node != NULL) {
            res.push_back(node->val);
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};