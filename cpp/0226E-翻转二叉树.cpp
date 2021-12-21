/*
 * @Author: SukiEva
 * @Date: 2021-12-21 09:32:47
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;
        if (right != nullptr) invertTree(right);
        if (left != nullptr) invertTree(left);
        return root;
    }
};