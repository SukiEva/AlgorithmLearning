/*
 * @Author: SukiEva
 * @Date: 2022-01-19 21:01:00
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            ans.push_back(node->val);
            if (node->left != nullptr) que.push(node->left);
            if (node->right != nullptr) que.push(node->right);
        }
        return ans;
    }
};