/*
 * @Author: SukiEva
 * @Date: 2021-08-05 16:59:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/merge-two-sorted-lists/
#include "include/ListNode.h"

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode;
        ListNode* p = h;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = (l1 == nullptr) ? l2 : l1;
        p = h->next;
        delete h;
        return p;
    }
};