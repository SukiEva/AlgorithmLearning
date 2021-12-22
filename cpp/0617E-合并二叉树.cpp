/*
 * @Author: SukiEva
 * @Date: 2021-12-22 09:08:42
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        else if (root1 == nullptr) {
            return root2;
        } else if (root2 == nullptr) {
            return root1;
        } else {
            root1->val = root2->val + root1->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            delete (root2);
            return root1;
        }
    }
};