/*
 * @Author: SukiEva
 * @Date: 2022-01-20 19:29:32
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    bool dfs(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr || A->val != B->val) return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }

   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        return dfs(A, B) || isSubStructure(A->left, B) ||
               isSubStructure(A->right, B);
    }
};