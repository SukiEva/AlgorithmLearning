/*
 * @Author: SukiEva
 * @Date: 2022-01-26 16:31:14
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (head != nullptr) {
            if (head->val == val) {
                pre->next = head->next;
                break;
            }
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }
};