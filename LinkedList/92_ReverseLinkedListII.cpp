#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (cur != NULL && count < m) {
            prev = cur;
            cur = cur->next;
            ++count;
        }
        ListNode* beg = cur;
        ListNode* end = NULL;
        while (cur != NULL && count <= n) {
            next = cur->next;
            cur->next = end;
            end = cur;
            cur = next;
            ++count;
        }
        if (prev != NULL)
            prev->next = end;
        beg->next = next;
        return (prev == NULL) ? end : head;
    }
};