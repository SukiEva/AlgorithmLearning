/*
 * @Author: SukiEva
 * @Date: 2022-02-06 20:29:31
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 || right == 0)
            return left + right + 1;
        else
            return min(left, right) + 1;
    }
};