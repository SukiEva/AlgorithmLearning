/*
 * @Author: SukiEva
 * @Date: 2021-12-23 10:38:02
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        return root;
    }
};