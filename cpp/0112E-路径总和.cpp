/*
 * @Author: SukiEva
 * @Date: 2021-12-21 10:57:19
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int target;
    bool ans = false;
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) ans = true;
            return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root, 0);
        return ans;
    }
};