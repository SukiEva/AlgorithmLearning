/*
 * @Author: SukiEva
 * @Date: 2021-12-13 10:55:08
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *node = dummy, *cur = dummy;
        while (n-- && node != nullptr) node = node->next;
        node = node->next;
        while (node != nullptr) {
            node = node->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};