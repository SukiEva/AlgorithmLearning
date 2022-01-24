/*
 * @Author: SukiEva
 * @Date: 2022-01-24 21:21:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    struct cmp {
        bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val > n2->val;
        }
    };

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (auto node : lists) {
            if (node != nullptr) que.push(node);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!que.empty()) {
            auto node = que.top();
            que.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr) que.push(node->next);
        }
        return dummy->next;
    }
};