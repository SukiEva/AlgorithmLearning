/*
 * @Author: SukiEva
 * @Date: 2022-02-10 13:23:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        queue<TreeNode*> que;
        que.push(root);
        ostringstream out;
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (node != nullptr) {
                out << node->val << ' ';
                que.push(node->left);
                que.push(node->right);
            } else
                out << '#' << ' ';
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<TreeNode*> nodes;
        istringstream in(data);
        string val;
        while (in >> val) {
            if (val == "#")
                nodes.push_back(nullptr);
            else
                nodes.push_back(new TreeNode(stoi(val)));
        }
        int p = 1;
        for (auto node : nodes) {
            if (node == nullptr) continue;
            node->left = nodes[p++];
            node->right = nodes[p++];
        }
        return nodes[0];
    }
};