/*
 * @Author: SukiEva
 * @Date: 2021-12-13 09:56:40
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

   private:
    ListNode *dummy;
    int size;

   public:
    MyLinkedList() {
        dummy = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode *node = dummy->next;
        while (index--) {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(size, val); }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        size++;
        ListNode *node = dummy;  // 前驱
        while (index--) node = node->next;
        ListNode *nNode = new ListNode(val);
        nNode->next = node->next;
        node->next = nNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        size--;
        ListNode *node = dummy;  // 前驱
        while (index--) node = node->next;
        node->next = node->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */