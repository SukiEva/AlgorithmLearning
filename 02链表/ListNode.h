#ifndef LISTNODE_HEADER
#define LISTNODE_HEADER

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* InitData(std::vector<int>& a);
void OutPut(ListNode* L);
#endif