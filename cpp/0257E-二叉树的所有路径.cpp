/*
 * @Author: SukiEva
 * @Date: 2021-12-21 10:31:08
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<string> ans;

    void dfs(TreeNode* node, string tmp) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(tmp + to_string(node->val));
            return;
        }
        dfs(node->left, tmp + to_string(node->val) + "->");
        dfs(node->right, tmp + to_string(node->val) + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};