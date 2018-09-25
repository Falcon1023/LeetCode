public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode node = new ListNode(0);
        ListNode res = node;
        while (head != null) {
            if (head.val != val) {
                node.next = head;
                node = node.next;
            }
            head = head.next;
            if (head == null)
                node.next = null;
        }
        return res.next;
    }
}

 class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
 }
