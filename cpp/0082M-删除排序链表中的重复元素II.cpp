/*
 * @Author: SukiEva
 * @Date: 2022-02-03 21:57:22
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(101);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next != nullptr && cur->next->val == x)
                    cur->next = cur->next->next;
            } else
                cur = cur->next;
        }

        return dummy->next;
    }
};