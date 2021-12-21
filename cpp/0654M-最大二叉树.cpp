/*
 * @Author: SukiEva
 * @Date: 2021-12-21 15:31:33
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        if (maxIndex > 0) {
            vector<int> left(nums.begin(), nums.begin() + maxIndex);
            root->left = constructMaximumBinaryTree(left);
        }
        if (maxIndex < nums.size() - 1) {
            vector<int> right(nums.begin() + maxIndex + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};
