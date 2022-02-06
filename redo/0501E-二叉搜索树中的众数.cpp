/*
 * @Author: SukiEva
 * @Date: 2022-02-06 21:02:40
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    vector<int> ans;
    int m = 0;
    int cnt = 0;
    TreeNode* pre = nullptr;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (pre != nullptr && pre->val == root->val)
            cnt++;
        else
            cnt = 1;
        pre = root;
        if (cnt >= m) {
            if (cnt > m) ans.clear();
            m = cnt;
            ans.push_back(root->val);
        }
        dfs(root->right);
    }

   public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};