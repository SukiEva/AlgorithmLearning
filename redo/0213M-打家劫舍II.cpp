/*
 * @Author: SukiEva
 * @Date: 2022-02-12 20:31:21
 * @Description: https://github.com/SukiEva
 * わたし、気になります！
 */
#include <bits/stdc++.h>

#include "include/ListNode.h"
#include "include/TreeNode.h"

using namespace std;

class Solution {
   private:
    int robLine(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(dp[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }

   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(robLine(nums, 0, nums.size() - 2),
                   robLine(nums, 1, nums.size() - 1));
    }
};