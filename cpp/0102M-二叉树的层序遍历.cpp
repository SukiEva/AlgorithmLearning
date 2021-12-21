/*
 * @Author: SukiEva
 * @Date: 2021-12-21 09:19:13
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
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> que;
        vector<int> tmp;
        que.push(root);
        while (!que.empty()) {
            int l = que.size();
            while (l--) {
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};