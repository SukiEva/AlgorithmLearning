// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
// 走到尽头见不到你，于是走过你来时的路，等到相遇时才发现，你也走过我来时的路。
// 若相交，链表A： a+c, 链表B : b+c. a+c+b+c = b+c+a+c 。则会在公共处c起点相遇。若不相交，a+b = b+a 。因此相遇处是NULL
#include "ListNode.h"
using namespace std;

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = (pa == nullptr) ? headB : pa->next;
            pb = (pb == nullptr) ? headA : pb->next;
        }
        return pa;
    }
};
