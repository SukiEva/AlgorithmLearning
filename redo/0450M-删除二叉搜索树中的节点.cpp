/*
 * @Author: SukiEva
 * @Date: 2022-02-06 21:19:49
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        // 两个子树都不为空
        TreeNode* node = root->right;
        while (node->left != nullptr) node = node->left;
        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
        return root;
    }
};