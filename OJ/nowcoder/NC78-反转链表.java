/***
描述
输入一个链表，反转链表后，输出新链表的表头。
示例1
输入：

{1,2,3}

返回值：

{3,2,1}
 **/



public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
public class Solution {
    public ListNode ReverseList(ListNode head) {
        ListNode p = null;
        ListNode q = head;
        
        while (q != null) {
            ListNode tmp = q.next;
            q.next = p;
            p = q;
            q = tmp;
        }
        
        return p;
    }
}
