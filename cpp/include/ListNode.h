/*
 * @Author: SukiEva
 * @Date: 2021-11-13 09:33:05
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#ifndef LISTNODE_HEADER
#define LISTNODE_HEADER

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif