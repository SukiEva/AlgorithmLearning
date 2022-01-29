/*
 * @Author: SukiEva
 * @Date: 2022-01-29 21:41:41
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            head = head->next;
            fast = fast->next->next;
        }
        return head;
    }
};