/*
 * @Author: SukiEva
 * @Date: 2021-08-04 22:52:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/reverse-linked-list/

#include "include/ListNode.h"
using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur=head;
        while (cur!=nullptr){
            ListNode* next = cur->next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};