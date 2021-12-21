/*
 * @Author: SukiEva
 * @Date: 2021-12-21 10:43:17
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int ans = 0;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr && root->left->left == nullptr &&
            root->left->right == nullptr)
            ans += root->left->val;
        dfs(root->left);
        dfs(root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};