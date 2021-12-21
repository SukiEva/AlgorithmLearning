/*
 * @Author: SukiEva
 * @Date: 2021-12-21 10:10:45
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
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (leftDepth == 0 || rightDepth == 0)
            return leftDepth + rightDepth + 1;
        if (leftDepth < rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }
};