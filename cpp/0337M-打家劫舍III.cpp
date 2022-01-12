/*
 * @Author: SukiEva
 * @Date: 2022-01-12 19:37:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int rob(TreeNode* root) {
        vector<int> ans = robTree(root);
        return max(ans[0], ans[1]);
    }

    vector<int> robTree(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        int v1 = max(left[0], left[1]) + max(right[0], right[1]);
        int v2 = left[0] + right[0] + root->val;
        return {v1, v2};
    }
};