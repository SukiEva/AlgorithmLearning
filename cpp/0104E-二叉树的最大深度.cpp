/*
 * @Author: SukiEva
 * @Date: 2021-12-21 10:05:25
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int depth = 0;

    void dfs(TreeNode* node, int cnt) {
        if (node == nullptr) {
            depth = max(depth, cnt);
            return;
        }
        dfs(node->left, cnt + 1);
        dfs(node->right, cnt + 1);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return depth;
    }
};