/*
 * @Author: SukiEva
 * @Date: 2022-02-23 21:36:51
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
        if (head == nullptr) return head;
        if (!mp.count(head)) {
            Node* node = new Node(head->val);
            mp[head] = node;
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};