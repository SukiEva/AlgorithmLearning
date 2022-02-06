/*
 * @Author: SukiEva
 * @Date: 2022-02-06 20:18:36
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node == nullptr) {
                ans.push_back(st.top()->val);
                st.pop();
                continue;
            }
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
            st.push(node);
            st.push(nullptr);
        }
        return ans;
    }
};