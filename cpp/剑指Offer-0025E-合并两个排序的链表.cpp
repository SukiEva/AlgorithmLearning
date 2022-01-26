/*
 * @Author: SukiEva
 * @Date: 2022-01-26 16:40:02
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            }
        }
        if (list1 != nullptr) cur->next = list1;
        if (list2 != nullptr) cur->next = list2;
        return dummy->next;
    }
};