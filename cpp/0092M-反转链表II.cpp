/*
 * @Author: SukiEva
 * @Date: 2022-01-24 20:42:57
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* pre = tail->next;
        ListNode* cur = head;
        while (pre != tail) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return tail;
    }

   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        right -= left;
        while (left-- > 1) {
            pre = head;
            head = head->next;
        }
        while (right--) {
            head = head->next;
        }
        ListNode* res = reverse(pre->next, head);
        pre->next = res;
        return dummy->next;
    }
};