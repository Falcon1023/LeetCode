#include <cstddef>
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int prevVal = head->val;
        while (cur != NULL) {
            if (cur->val == prevVal) {
                free(prev->next);
                prev->next = cur->next;
            } else {
                prev = cur;
                prevVal = cur->val;
            }
            cur = cur->next;
        }
        return head;
    }
};

