/*
 * @Author: SukiEva
 * @Date: 2021-12-13 14:49:56
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pa = head, *pb = head;
        while (pb != nullptr && pb->next != nullptr) {
            pa = pa->next;
            pb = pb->next->next;
            if (pa == pb) {
                pa = head;
                while (pa != pb) {
                    pa = pa->next;
                    pb = pb->next;
                }
                return pa;
            }
        }
        return nullptr;
    }
};
