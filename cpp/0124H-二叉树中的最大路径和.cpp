/*
 * @Author: SukiEva
 * @Date: 2022-01-29 22:03:09
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int ans = -10000;

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        ans = max(ans, left + right + root->val);
        return root->val + max(left, right);
    }

   public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};