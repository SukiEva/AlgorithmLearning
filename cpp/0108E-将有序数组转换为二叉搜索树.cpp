/*
 * @Author: SukiEva
 * @Date: 2021-08-18 09:04:20
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */

// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
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
