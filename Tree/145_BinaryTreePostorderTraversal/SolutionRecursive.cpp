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
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return res;
    }
    
    void postOrder(TreeNode *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            res.push_back(node->val);
        }
    }
};