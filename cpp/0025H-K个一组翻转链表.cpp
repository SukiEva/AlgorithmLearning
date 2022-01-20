/*
 * @Author: SukiEva
 * @Date: 2022-01-20 20:32:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode* pre = tail->next;
        ListNode* cur = head;
        while (pre != tail) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return {tail, head};
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (head) {
            ListNode* tail = pre;
            int t = k;
            while (t--) {  // 不足 k 个，直接返回
                tail = tail->next;
                if (tail == nullptr) return dummy->next;
            }
            ListNode* nex = tail->next;
            auto result = reverseList(head, tail);
            head = result.first;
            tail = result.second;

            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};