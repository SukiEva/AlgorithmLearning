/*
 * @Author: SukiEva
 * @Date: 2022-01-29 21:14:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            head = head->next;
            fast = fast->next->next;
        }
        return head;
    }

    ListNode* reverseNode(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* nex = head->next;
            head->next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }

    void mergeNodes(ListNode* l1, ListNode* l2) {
        ListNode *n1, *n2;
        while (l1 != nullptr && l2 != nullptr) {
            n1 = l1->next;
            n2 = l2->next;

            l1->next = l2;
            l1 = n1;

            l2->next = l1;
            l2 = n2;
        }
    }

   public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* mid = middleNode(head);
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseNode(l2);
        mergeNodes(head, l2);
    }
};