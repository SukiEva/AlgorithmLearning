/*
 * @Author: SukiEva
 * @Date: 2022-02-04 20:51:46
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        head = dummy;
        while (n--) fast = fast->next;
        fast = fast->next;
        while (fast != nullptr) {
            head = head->next;
            fast = fast->next;
        }
        head->next = head->next->next;
        return dummy->next;
    }
};