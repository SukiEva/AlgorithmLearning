/*
 * @Author: SukiEva
 * @Date: 2021-12-22 10:19:26
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* pre = nullptr;  // 记录左边的结点

    bool isValidBST(TreeNode* root) {  // 中序遍历递增
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
