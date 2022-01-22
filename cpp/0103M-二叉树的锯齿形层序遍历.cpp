/*
 * @Author: SukiEva
 * @Date: 2022-01-22 19:38:38
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        deque<int> tmp;
        que.push(root);
        bool flag = true;
        while (!que.empty()) {
            int l = que.size();
            while (l--) {
                TreeNode* node = que.front();
                que.pop();
                if (flag)
                    tmp.push_back(node->val);
                else
                    tmp.push_front(node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }

            ans.push_back(vector<int>(tmp.begin(), tmp.end()));
            flag = !flag;
            tmp.clear();
        }
        return ans;
    }
};
