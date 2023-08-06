package solutions.java;

import infrastructure.pojo.ListNode;

public class IntersectionOfTwoLinkedLists {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pa = headA, pb = headB;
        while (pa != null && pb != null) {
            if (pa == pb) {
                return pa;
            }
            pa = pa.next;
            pb = pb.next;
            if (pa == null && pb == null) {
                return null;
            }
            if (pa == null) {
                pa = headB;
            }
            if (pb == null) {
                pb = headA;
            }
        }
        return null;
    }
}