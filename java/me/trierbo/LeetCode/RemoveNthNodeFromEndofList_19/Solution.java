package me.trierbo.LeetCode.RemoveNthNodeFromEndofList_19;

public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode node = head;
        int count = 0, pos;
        while (node != null) {
            count++;
            node = node.next;
        }
        pos = count - n + 1;
        if (pos == 1)
            return head.next;
        count = 0;
        node = head;
        while (pos-1 != count) {
            count++;
            if (pos-1 == count) {
                node.next = node.next.next;
                break;
            } else {
                node = node.next;
            }
        }
        return head;
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}