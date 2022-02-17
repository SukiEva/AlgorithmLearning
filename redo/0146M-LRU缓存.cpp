/*
 * @Author: SukiEva
 * @Date: 2022-02-17 20:19:57
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

struct DLinkNode {
    int key;
    int val;
    DLinkNode* prev;
    DLinkNode* next;
    DLinkNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _val)
        : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
   private:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode* head;
    DLinkNode* tail;
    int size;
    int cap;

    void moveToHead(DLinkNode* node) {
        rmNode(node);
        addToHead(node);
    }

    void addToHead(DLinkNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void rmNode(DLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

   public:
    LRUCache(int _cap) : cap(_cap), size(0) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkNode* node = cache[key];
            node->val = value;
            moveToHead(node);
            return;
        }
        DLinkNode* node = new DLinkNode(key, value);
        cache[key] = node;
        addToHead(node);
        if (++size > cap) {
            DLinkNode* tailNode = tail->prev;
            rmNode(tailNode);
            cache.erase(tailNode->key);
            delete (tailNode);
            size--;
        }
    }
};