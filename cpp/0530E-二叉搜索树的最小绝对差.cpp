/*
 * @Author: SukiEva
 * @Date: 2021-12-22 10:35:13
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int pre = -1;
    int ans = 1e5 + 10;

    void traveral(TreeNode* root) {
        if (root == nullptr) return;
        traveral(root->left);
        if (pre != -1) ans = min(ans, root->val - pre);
        pre = root->val;
        traveral(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traveral(root);
        return ans;
    }
};