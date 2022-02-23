/*
 * @Author: SukiEva
 * @Date: 2022-02-23 21:48:44
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 利用 next 模拟队列进行操作
class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        Node* cur = root;
        while (cur != nullptr) {
            Node* dummy = new Node(0);  // 下一行链表的头结点
            Node* pre = dummy;
            while (cur != nullptr) {
                if (cur->left != nullptr) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right != nullptr) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;  // 下一行
        }
        return root;
    }
};