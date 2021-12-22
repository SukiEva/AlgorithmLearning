/*
 * @Author: SukiEva
 * @Date: 2021-12-22 10:16:41
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val < val) return searchBST(root->right, val);
        if (root->val > val) return searchBST(root->left, val);
        return root;
    }
};