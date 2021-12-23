/*
 * @Author: SukiEva
 * @Date: 2021-12-23 11:05:54
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
        if (root->val > key) {  // 向左找
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {  // 向右找
            root->right = deleteNode(root->right, key);
            return root;
        }
        // 只有一个孩子(包含是叶子，返回nullptr)
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        // 两个孩子
        TreeNode* minNode = root->right;  // 右子树最左结点
        while (minNode->left != nullptr) minNode = minNode->left;
        root->val = minNode->val;  // 替代被删除结点
        root->right = deleteNode(root->right, minNode->val);  // 删除替代的结点
        return root;
    }
};