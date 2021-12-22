/*
 * @Author: SukiEva
 * @Date: 2021-12-22 10:46:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> ans;
    TreeNode* pre = nullptr;
    int cnt = 0;
    int Max = 0;
    void traversal(TreeNode* root) {
        if (root == nullptr) return;
        traversal(root->left);
        if (pre == nullptr)
            cnt = 1;
        else if (pre->val == root->val)
            cnt++;
        else
            cnt = 1;
        pre = root;

        if (cnt == Max)
            ans.push_back(root->val);
        else if (cnt > Max) {
            Max = cnt;
            ans.clear();
            ans.push_back(root->val);
        }
        traversal(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return ans;
    }
};