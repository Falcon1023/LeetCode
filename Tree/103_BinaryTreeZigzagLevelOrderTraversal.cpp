#include <cstddef>
#include <vector>
#include <stack>
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
    stack<TreeNode*> cur;
    stack<TreeNode*> next;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return res;
        stack<TreeNode*>* pCur = &cur;
        stack<TreeNode*>* pNext = &next;
        bool leftToRight = true;
        pCur->push(root);
        while (!pCur->empty()) {
            int level = pCur->size();
            vector<int> levelRes;
            for (int i = 0; i < level; ++i) {
                TreeNode* tmpNode = pCur->top();
                pCur->pop();
                levelRes.push_back(tmpNode->val);
                if (leftToRight) {
                    if (tmpNode->left)
                        pNext->push(tmpNode->left);
                    if (tmpNode->right)
                        pNext->push(tmpNode->right);
                } else {
                    if (tmpNode->right)
                        pNext->push(tmpNode->right);
                    if (tmpNode->left)
                        pNext->push(tmpNode->left);
                }
            }
            leftToRight = !leftToRight;
            stack<TreeNode*>* tmpStack = pCur;
            pCur = pNext;
            pNext = tmpStack;
            res.push_back(levelRes);
        }
        return res;
    }
};
