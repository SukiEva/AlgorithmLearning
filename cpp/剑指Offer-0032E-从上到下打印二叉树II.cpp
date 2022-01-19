/*
 * @Author: SukiEva
 * @Date: 2022-01-19 21:00:18
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> tmp;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int len = que.size();
            tmp.clear();
            while (len--) {
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};