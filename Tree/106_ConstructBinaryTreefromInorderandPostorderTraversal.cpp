#include <cstddef>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildSubTree(inorder, postorder, postorder.size() - 1, 0, inorder.size());
    }

    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int parentIndex, int left, int right) {
        if (left >= right)
            return NULL;
        TreeNode *subtree = new TreeNode(postorder[parentIndex]);
        int pos = find(inorder.begin() + left, inorder.begin() + right, subtree->val) - inorder.begin();
        subtree->left = buildSubTree(inorder, postorder, parentIndex - right + pos, left, pos);
        subtree->right = buildSubTree(inorder, postorder, parentIndex - 1, pos + 1, right);
        return subtree;
    }
};

