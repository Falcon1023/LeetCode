public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head=null;
		ListNode l=null;
		int flag=0;
		while(l1!=null&&l2!=null){
			int num=l1.val+l2.val+flag;
			if(num>=10){
				num=num%10;
				flag=1;
			}else{
				flag=0;
			}
			if(l==null){
				l=new ListNode(num);
				head=l;
			}else{
				l.next=new ListNode(num);
				l=l.next;
			}
			l1=l1.next;
			l2=l2.next;
		}
		while(l1!=null){
			int num=l1.val+flag;
			if(num>=10){
				num=num%10;
				flag=1;
			}else{
				flag=0;
			}
			l.next=new ListNode(num);
			l=l.next;
			l1=l1.next;
		}
		while(l2!=null){
			int num=l2.val+flag;
			if(num>=10){
				num=num%10;
				flag=1;
			}else{
				flag=0;
			}
			l.next=new ListNode(num);
			l=l.next;
			l2=l2.next;
		}
		if(flag==1)
			l.next=new ListNode(flag);
		return head;
    }
}

class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}