/*
 * @Author: SukiEva
 * @Date: 2022-02-06 20:53:40
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    TreeNode* pre = nullptr;

   public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool l = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;
        bool r = isValidBST(root->right);
        return l && r;
    }
};