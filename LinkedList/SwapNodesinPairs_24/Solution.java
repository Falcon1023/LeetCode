package me.trierbo.LeetCode.SwapNodesinPairs_24;

public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode tmp = head;
        while (tmp != null && tmp.next != null) {
            int temp = tmp.val;
            tmp.val = tmp.next.val;
            tmp.next.val = temp;
            tmp = tmp.next.next;
        }
        return head;
    }
}


class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
