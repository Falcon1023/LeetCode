#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* beg = new ListNode(0);
        beg->next = head;
        ListNode* cur = beg;
        while(cur->next != NULL && cur->next->next != NULL) {
            if (cur->next->val == cur->next->next->val) {
                int tmp = cur->next->val;
                ListNode* prev = NULL;
                while (cur->next && cur->next->val == tmp) {
                    prev = cur->next;
                    cur->next = cur->next->next;
                    free(prev);
                }
            } else {
                cur = cur->next;
            }
        }
        return beg->next;
    }
};
