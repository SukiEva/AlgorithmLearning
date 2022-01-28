/*
 * @Author: SukiEva
 * @Date: 2022-01-28 14:32:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int ans;
    int cnt;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->right);
        if (cnt == 0) return;
        if (--cnt == 0) ans = root->val;
        dfs(root->left);
    }

   public:
    int kthLargest(TreeNode* root, int k) {
        cnt = k;
        dfs(root);
        return ans;
    }
};