/*
 * @Author: SukiEva
 * @Date: 2021-12-21 09:11:59
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
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != nullptr) {
                if (node->right != nullptr) st.push(node->right);
                if (node->left != nullptr) st.push(node->left);
                st.push(node);
                st.push(nullptr);
            } else {
                ans.push_back(st.top()->val);
                st.pop();
            }
        }
        return ans;
    }
};