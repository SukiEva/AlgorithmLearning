/*
 * @Author: SukiEva
 * @Date: 2022-01-28 14:10:07
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/Node.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    Node* pre = nullptr;
    Node* head;
    void dfs(Node* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (pre != nullptr)
            pre->right = root;
        else
            head = root;
        root->left = pre;
        pre = root;
        dfs(root->right);
    }

   public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};