/*
 * @Author: SukiEva
 * @Date: 2021-12-13 10:41:51
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* node = head->next;
        head->next = swapPairs(node->next);
        node->next = head;
        return node;
    }
};