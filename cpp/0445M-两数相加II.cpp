/*
 * @Author: SukiEva
 * @Date: 2022-02-22 12:59:24
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
        stack<int> s1, s2;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int t = 0;
        ListNode* pre = nullptr;
        while (!s1.empty() || !s2.empty()) {
            int sum = t;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            t = sum / 10;
            sum %= 10;
            ListNode* cur = new ListNode(sum);
            cur->next = pre;
            pre = cur;
        }
        if (t == 0) return pre;
        ListNode* ans = new ListNode(t);
        ans->next = pre;
        return ans;
    }
};