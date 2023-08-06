package solutions.java;

import infrastructure.pojo.ListNode;

public class RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head;
        ListNode dummy = new ListNode(0, head);
        head = dummy;
        while (n-- != 0) {
            fast = fast.next;
        }
        while (fast != null) {
            head = head.next;
            fast = fast.next;
        }
        head.next = head.next.next;
        return dummy.next;
    }
}