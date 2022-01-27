/*
 * @Author: SukiEva
 * @Date: 2022-01-27 22:19:15
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (node != nullptr) {
                if (node->right != nullptr) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left != nullptr) st.push(node->left);
            } else {
                ans.push_back(st.top()->val);
                st.pop();
            }
        }
        return ans;
    }
};