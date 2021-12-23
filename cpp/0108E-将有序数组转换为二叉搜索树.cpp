/*
 * @Author: SukiEva
 * @Date: 2021-12-23 11:48:14
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>
#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return new TreeNode(nums[0]);
        int middle = len >> 1;
        TreeNode* T = new TreeNode(nums[middle]);
        if (len == 2)
            T->left = new TreeNode(nums[0]);
        else {
            vector<int> left(nums.begin(), nums.begin() + middle);
            vector<int> right(nums.begin() + middle + 1, nums.end());
            T->left = sortedArrayToBST(left);
            T->right = sortedArrayToBST(right);
        }
        return T;
    }
};