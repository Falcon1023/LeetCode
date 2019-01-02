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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildSubTree(preorder, inorder, 0, 0, inorder.size());
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int parentIndex, int left, int right) {
        if (left >= right)
            return NULL;
        TreeNode *subtree = new TreeNode(preorder[parentIndex]);
        int pos = find(inorder.begin()+left, inorder.begin()+right, subtree->val) - inorder.begin();
        subtree->left = buildSubTree(preorder, inorder, parentIndex+1, left, pos);
        subtree->right = buildSubTree(preorder, inorder, parentIndex+pos-left+1, pos+1, right);
        return subtree;
    }
};
