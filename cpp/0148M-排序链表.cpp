/*
 * @Author: SukiEva
 * @Date: 2022-02-17 17:36:08
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;
        return dummy->next;
    }

    ListNode* midNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            head = head->next;
            fast = fast->next->next;
        }
        return head;
    }

   public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* mid = midNode(head);
        ListNode* nhead = mid->next;
        mid->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(nhead);
        return merge(left, right);
    }
};
