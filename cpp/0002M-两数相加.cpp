/*
 * @Author: SukiEva
 * @Date: 2022-02-03 22:22:48
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int add = 0;
        while (l1 != nullptr || l2 != nullptr || add) {
            int t = (l1 == nullptr ? 0 : l1->val) +
                    (l2 == nullptr ? 0 : l2->val) + add;
            ListNode* node = new ListNode(t % 10);
            add = t / 10;
            cur->next = node;
            cur = node;
            l1 = (l1 == nullptr) ? l1 : l1->next;
            l2 = (l2 == nullptr) ? l2 : l2->next;
        }
        return dummy->next;
    }
};

// 原地修改，对，但是丑
class Solution2 {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = l1;
        int add = 0;
        ListNode* pre = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            int t = l1->val + l2->val + add;
            l1->val = t % 10;
            add = (t >= 10) ? 1 : 0;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2 != nullptr) {
            pre->next = l2;
            l1 = l2;
        }
        while (l1 != nullptr) {
            int t = l1->val + add;
            l1->val = t % 10;
            add = (t >= 10) ? 1 : 0;
            if (l1->next == nullptr && add) {
                l1->next = new ListNode(1);
                add = 0;
                break;
            } else
                l1 = l1->next;
        }
        if (add) pre->next = new ListNode(1);
        return dummy->next;
    }
};