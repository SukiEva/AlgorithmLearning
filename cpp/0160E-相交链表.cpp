/*
 * @Author: SukiEva
 * @Date: 2021-12-13 14:39:11
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            if (pa == nullptr)
                pa = headB;
            else
                pa = pa->next;
            if (pb == nullptr)
                pb = headA;
            else
                pb = pb->next;
        }
        return pa;
    }
};