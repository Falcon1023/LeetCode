#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        reverse(head, prev);
        return prev;
    }

    void reverse(ListNode* head, ListNode* &prev) {
        if (head != NULL) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            reverse(head, prev);
        }
    }
};