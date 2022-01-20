/*
 * @Author: SukiEva
 * @Date: 2022-01-20 19:46:39
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* t = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(t);
        return root;
    }
};