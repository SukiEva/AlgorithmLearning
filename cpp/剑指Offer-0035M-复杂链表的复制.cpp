/*
 * @Author: SukiEva
 * @Date: 2022-01-15 15:03:35
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   private:
    unordered_map<Node*, Node*> mp;

   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (!mp.count(head)) {
            Node* node = new Node(head->val);
            mp[head] = node;
            node->next = copyRandomList(head->next);
            node->random = mp[head->random];
        }
        return mp[head];
    }
};