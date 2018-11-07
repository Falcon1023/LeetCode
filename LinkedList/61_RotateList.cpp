#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        int num = 0;
        ListNode* cur = head;
        ListNode* tail = NULL;
        while(cur != NULL) {
            ++num;
            tail = cur;
            cur = cur->next;
        }
        int remainder = k % num;
        if (remainder == 0)
            return head;
        cur = head;
        for (int i = 1; i < num - remainder; ++i)
            cur = cur->next;
        tail->next = head;
        tail = cur->next;
        cur->next = NULL;
        return tail;
    }
};