/*
 * @Author: SukiEva
 * @Date: 2022-02-24 17:24:46
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;  // 左边的较小数，尽量靠右
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) j--;  // 右边的较大数
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

class Solution2 {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (auto i : nums) {
            if (ans.empty() || i > ans.back()) {
                ans.push_back(i);
            } else {
                auto lb = lower_bound(ans.begin(), ans.end(), i);
                *lb = i;
            }
        }
        cout << "路径: ";
        for (auto i : ans) cout << i << ' ';
        return ans.size();
    }
};