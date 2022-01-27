/*
 * @Author: SukiEva
 * @Date: 2022-01-27 22:35:53
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int l = que.size();
            while (l) {
                auto node = que.front();
                que.pop();
                if (l == 1) ans.push_back(node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
                l--;
            }
        }
        return ans;
    }
};