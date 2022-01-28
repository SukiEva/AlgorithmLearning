/*
 * @Author: SukiEva
 * @Date: 2022-01-28 13:49:30
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(TreeNode* root, int target) {
        if (root == nullptr) return;
        tmp.push_back(root->val);
        target -= root->val;
        if (root->left == nullptr && root->right == nullptr && target == 0) {
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        dfs(root->left, target);
        dfs(root->right, target);
        tmp.pop_back();
    }

   public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};