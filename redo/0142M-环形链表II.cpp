/*
 * @Author: SukiEva
 * @Date: 2022-02-04 20:56:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (head != fast) {
                    head = head->next;
                    fast = fast->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};