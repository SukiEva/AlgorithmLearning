/*
 * @Author: SukiEva
 * @Date: 2022-02-12 20:37:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    vector<int> robTree(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto l = robTree(root->left);
        auto r = robTree(root->right);
        int tou = l[0] + r[0] + root->val;
        int ntou = max(l[0], l[1]) + max(r[0], r[1]);
        return {ntou, tou};
    }

   public:
    int rob(TreeNode* root) {
        auto ans = robTree(root);
        return max(ans[0], ans[1]);
    }
};