/*
 * @Author: SukiEva
 * @Date: 2021-12-23 19:15:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->right = convertBST(root->right);
        root->val = root->val + sum;
        sum = root->val;
        root->left = convertBST(root->left);
        return root;
    }
};