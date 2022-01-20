/*
 * @Author: SukiEva
 * @Date: 2022-01-20 19:50:28
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    bool check(TreeNode* A, TreeNode* B) {
        if (A == nullptr && B == nullptr) return true;
        if (A == nullptr || B == nullptr) return false;
        if (A->val != B->val) return false;
        return check(A->left, B->right) && check(A->right, B->left);
    }

   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return check(root->left, root->right);
    }
};