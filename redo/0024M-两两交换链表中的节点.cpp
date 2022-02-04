/*
 * @Author: SukiEva
 * @Date: 2022-02-04 20:47:42
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
        ListNode* nex = head->next;
        head->next = swapPairs(nex->next);
        nex->next = head;
        return nex;
    }
};